FCACHE_CREATE_CALLBACK FcacheCreateCallback;

HANDLE FcacheCreateCallback(
  [in]  LPSTR lpstrName,
  [in]  LPVOID lpvData,
  [out] DWORD *cbFileSize,
  [out] DWORD *cbFileSizeHigh
)
{...}