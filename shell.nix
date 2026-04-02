
{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    gnuplot
    cmake
    ninja
  ];

  shellHook = ''
    export CMAKE_GENERATOR=Ninja
  '';
}
