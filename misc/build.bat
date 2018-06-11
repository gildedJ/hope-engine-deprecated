@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall" x86

set workspace=C:\Users\jacksonj\Desktop\Junk Bin\dagobah\Hope Engine
set SDLPath=%workspace%\..\SDL

set compilerFlags=/Od /Zi /EHsc -I"%SDLPath%\include"
set linkerFlags=/link /SUBSYSTEM:CONSOLE /OUT:hope.exe /LIBPATH:"%SDLPath%\lib\x86" sdl2.lib sdl2main.lib sdl2_image.lib

pushd "%workspace%/build"

cl %compilerFlags% ../src/*.cpp %linkerFlags%

popd