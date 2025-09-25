BOOL SetFileInformationByHandle(
  [in] HANDLE                    hFile,
  [in] FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
  [in] LPVOID                    lpFileInformation,
  [in] DWORD                     dwBufferSize
);