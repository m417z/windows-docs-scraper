BOOL SetTokenInformation(
  [in] HANDLE                  TokenHandle,
  [in] TOKEN_INFORMATION_CLASS TokenInformationClass,
  [in] LPVOID                  TokenInformation,
  [in] DWORD                   TokenInformationLength
);