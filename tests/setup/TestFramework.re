let projectDir =
  try(Sys.getenv("RELY_ROOT_DIR")) {
  | e =>
    Console.error("[FATAL] RELY_ROOT_DIR environment variable not set.");
    raise(e);
  };

let (/) = Filename.concat;
let snapshotDir = projectDir / "tests" / "__snapshots__";

include Rely.Make({
  let config = Rely.TestFrameworkConfig.initialize({snapshotDir, projectDir});
});
