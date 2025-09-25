PFIND_EXE_FILE_CALLBACK PfindExeFileCallback;

BOOL PfindExeFileCallback(
  [in] HANDLE FileHandle,
  [in] PCSTR FileName,
  [in] PVOID CallerData
)
{...}