WINHTTP_STATUS_CALLBACK WinhttpStatusCallback;

VOID WinhttpStatusCallback(
  [in] HINTERNET hInternet,
  [in] DWORD_PTR dwContext,
  [in] DWORD dwInternetStatus,
  [in] LPVOID lpvStatusInformation,
  [in] DWORD dwStatusInformationLength
)
{...}