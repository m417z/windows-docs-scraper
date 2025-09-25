BOOL GetTokenInformation(
  [in]            HANDLE                  TokenHandle,
  [in]            TOKEN_INFORMATION_CLASS TokenInformationClass,
  [out, optional] LPVOID                  TokenInformation,
  [in]            DWORD                   TokenInformationLength,
  [out]           PDWORD                  ReturnLength
);