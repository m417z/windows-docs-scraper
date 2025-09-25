BOOL GetFileInformationByHandleEx(
  [in]  HANDLE                    hFile,
  [in]  FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
  [out] LPVOID                    lpFileInformation,
  [in]  DWORD                     dwBufferSize
);