#include <windows.h>

VOID
WINAPI
SetBitsPerPel(
	_In_ INT bits
) {
	 DEVMODEA dev;
	 dev.dmPelsWidth = GetSystemMetrics( 0 );
	 dev.dmPelsHeight = GetSystemMetrics( 1 );
	 dev.dmBitsPerPel = bits;
	 dev.dmFields = DM_BITSPERPEL;
	 dev.dmSize = sizeof( DEVMODE );
	 ChangeDisplaySettingsA( &dev, 0 );
}

INT
WINAPI
wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ PWSTR pszCmdLine,
	_In_ INT nShowCmd
) {
	if ( MessageBoxA(0, 0, 0, MB_YESNO | MB_ICONWARNING ) != IDYES )
		return FALSE;

	while ( TRUE ) {
		SetBitsPerPel( 16 );
		SetBitsPerPel( 8 );
	}
}