RasCustomDialFn Rascustomdialfn;

DWORD Rascustomdialfn(
  HINSTANCE hInstDll,
  LPRASDIALEXTENSIONS lpRasDialExtensions,
  LPCWSTR lpszPhonebook,
  LPRASDIALPARAMS lpRasDialParams,
  DWORD dwNotifierType,
  LPVOID lpvNotifier,
  LPHRASCONN lphRasConn,
  DWORD dwFlags
)
{...}