open TestFramework;

describe("ChessTea", ({test}) => {
  test("Strings", ({expect}) => {
    let actual = ChessTea.Const.hello;
    let expected = "Hello World!";
    expect.string(actual).toEqual(expected);
  });

  test("Snapshots", ({expect}) => {
    let actual = ChessTea.Const.hello;
    expect.string(actual).toMatchSnapshot();
  });
});
