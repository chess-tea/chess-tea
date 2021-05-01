# `chess_tea`

This is a Revery app.

## Template Init

There are two convenience scripts to initialize this repo:

- `scripts/rename chess_tea my_library`
  - This updates appropriate filenames and contents to use "my_library" as the name.
  - Arguments should be snake_case, they will be converted to other forms where appropriate.
- `scripts/vscode`
  - This sets up editor support for the [OCaml Platform](https://marketplace.visualstudio.com/items?itemName=ocamllabs.ocaml-platform) extension by creating `.vscode/settings.json`.
  - This can be done manually or inside VS Code, but I find this easier.

_Remove this section from the readme after completing the initialization._

## Install `esy`

Globally install [`esy`](https://www.npmjs.com/package/esy) so that the `esy`
command is available in the terminal.

```bash
npm install -g esy
```

_This may be useful: [Global npm without sudo](https://github.com/sindresorhus/guides/blob/master/npm-global-without-sudo.md)_

## Install the dependencies and build

```bash
esy
esy @app
esy @test
```

_This is a combination of `esy install` and `esy build`_

## Launch app

```bash
esy app
```

_This should automatically rebuild if there are changes_

## Run tests

```bash
esy test
```

_This should automatically rebuild if there are changes_

## More Details

- For more details and additional setup see: [`details.md`](details.md)
  - Editor support
  - Adding dependencies
  - Recursive dub-directories
  - Ignoring warnings
  - Printing stack traces

## Next Steps

For CI/CD, check out [`esy-ocaml/hello-reason`](https://github.com/esy-ocaml/hello-reason).
