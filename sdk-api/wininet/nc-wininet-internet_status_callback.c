INTERNET_STATUS_CALLBACK InternetStatusCallback;

VOID InternetStatusCallback(
  [in] HINTERNET hInternet,
  [in] DWORD_PTR dwContext,
  [in] DWORD dwInternetStatus,
  [in] LPVOID lpvStatusInformation,
  [in] DWORD dwStatusInformationLength
)
{...}