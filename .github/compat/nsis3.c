/* Build shim, not part of the plug-in: NSIS 3's plug-in API turned myatoi, popint
   and pushint into macros, so the functions this plug-in's bundled pluginapi.h
   still declares are no longer in the plug-in API library it links. */
#include <windows.h>
#include <nsis/pluginapi.h>

#undef myatoi
#undef popint
#undef pushint

int NSISCALL myatoi(LPCTSTR s) { return (int) nsishelper_str_to_ptr(s); }
int NSISCALL popint(void) { return (int) popintptr(); }
void NSISCALL pushint(int value) { pushintptr(value); }
