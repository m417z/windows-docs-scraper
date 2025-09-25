RasCustomScriptExecuteFn Rascustomscriptexecutefn;

DWORD Rascustomscriptexecutefn(
  [in] HANDLE hPort,
  [in] LPCWSTR lpszPhonebook,
  [in] LPCWSTR lpszEntryName,
  [in] PFNRASGETBUFFER pfnRasGetBuffer,
  [in] PFNRASFREEBUFFER pfnRasFreeBuffer,
  [in] PFNRASSENDBUFFER pfnRasSendBuffer,
  [in] PFNRASRECEIVEBUFFER pfnRasReceiveBuffer,
  [in] PFNRASRETRIEVEBUFFER pfnRasRetrieveBuffer,
  [in] HWND hWnd,
  [in] RASDIALPARAMS *pRasDialParams,
       PVOID pvReserved
)
{...}