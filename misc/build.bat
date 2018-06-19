@echo off

REM call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall" x86
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall" x86

REM set workspace=C:\Users\jacksonj\Desktop\Junk Bin\dagobah\Hope Engine
REM set SDLPath=%workspace%\..\SDL
set workspace=C:\Projects\HopeGit\hope-engine
set SDLPath=C:\SDL2

set compilerFlags=/Od /Zi /EHsc -I"%SDLPath%\include"
set linkerFlags=/link /SUBSYSTEM:CONSOLE /OUT:hope.exe /LIBPATH:"%SDLPath%\lib\x86" sdl2.lib sdl2main.lib sdl2_image.lib

pushd "%workspace%/build"

cl %compilerFlags% ../src/*.cpp %linkerFlags%

popd