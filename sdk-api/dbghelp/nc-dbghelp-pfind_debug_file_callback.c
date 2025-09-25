PFIND_DEBUG_FILE_CALLBACK PfindDebugFileCallback;

BOOL PfindDebugFileCallback(
  [in] HANDLE FileHandle,
  [in] PCSTR FileName,
  [in] PVOID CallerData
)
{...}