# Details

## Editor Support

### VSCode

- Install the [OCaml Platform](https://marketplace.visualstudio.com/items?itemName=ocamllabs.ocaml-platform) extension.
- Create `.vscode/settings.json` in this repo:

```json
{
  "ocaml.sandbox": {
    "kind": "esy",
    "root": "/path/to/this-repository"
  }
}
```

- Restart VSCode

### VIM

- For VIM support use: [`vim-reasonml`](https://github.com/jordwalke/vim-reasonml)
- (Or see the next section for general terminal editor use)

### Terminal Editors

- Run your editor within the Reason environment using `esy`:

```bash
esy $EDITOR
esy vim
```

## Adding Dependencies

- Add a line to `package.json` saying where the dependency is:

```json
{
  "dependencies": {
    "@reason-native/console": "^0.1.0"
  }
}
```

- Add a `libraries` section to the `dune` file
- The name comes from the `public_name` located in that library's `dune` file: [`console.lib`](https://github.com/facebookexperimental/reason-native/blob/master/src/console/dune#L3)

```
(executable
  (name Hello)
  (public_name hello)
  (package hello)
  (libraries
    console.lib
  )
)
```

- Now the `Console` module is available in your source code:

```reason
Console.log("Hello again!");
```

### Dependencies from GitHub commits

- It is easy to depend on a specific commit from github:
  - _Warning: Do not do this if your library will be consumed from other places. It makes dependency resolution a headache to get correct._

```json
{
  "dependencies": {
    "@reason-native/console": "*"
  },
  "resolutions": {
    "@reason-native/console": "facebookexperimental/reason-native:console.json#a33f1528"
  }
}
```

## Recursive Sub Directories

To use source code in sub-directories recursively add to the end of the `dune` file:

```
(include_subdirs unqualified)
```

Overall the file might look like:

```
(executable
  (name Hello)
  (public_name hello)
  (package hello)
)
(include_subdirs unqualified)
```

## Hide Warnings

- Some warnings are more noisy than helpful. Add `ocamlopt_flags` and `ocamlc_flags` to ignore specific warnings (9 and 27 in this example):

```
(executable
  (name Hello)
  (public_name hello)
  (package hello)
  (ocamlopt_flags -w -9-27)
  (ocamlc_flags -w -9-27)
)
```

## Printing Stack traces

- By default when an uncaught exception is raised the program prints the error message and no stack trace.
- To print the stack trace by default ensure that the environment variable `OCAMLRUNPARAM=b` is set.
- One way to set this variable using `esy` is in the `package.json`:

```json
{
  "esy": {
    "exportedEnv": {
      "OCAMLRUNPARAM": {
        "val": "b",
        "scope": "global"
      }
    }
  }
}
```

- Test this works by adding `1 / 0;` to a reason file and ensuring the stack trace is printed.
