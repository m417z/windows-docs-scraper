FCACHE_RICHCREATE_CALLBACK FcacheRichcreateCallback;

HANDLE FcacheRichcreateCallback(
  [in]  LPSTR lpstrName,
  [in]  LPVOID lpvData,
  [out] DWORD *cbFileSize,
  [out] DWORD *cbFileSizeHigh,
  [out] BOOL *pfDidWeScanIt,
  [out] BOOL *pfIsStuffed,
  [out] BOOL *pfStoredWithDots,
  [out] BOOL *pfStoredWithTerminatingDot
)
{...}