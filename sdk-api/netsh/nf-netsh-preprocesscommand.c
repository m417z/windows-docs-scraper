DWORD PreprocessCommand(
            HANDLE   hModule,
  [in, out] LPWSTR   *ppwcArguments,
  [in]      DWORD    dwCurrentIndex,
  [in]      DWORD    dwArgCount,
  [in]      TAG_TYPE *pttTags,
  [in]      DWORD    dwTagCount,
  [in]      DWORD    dwMinArgs,
  [in]      DWORD    dwMaxArgs,
  [out]     DWORD    *pdwTagType
);