BOOL GetProcessPreferredUILanguages(
  [in]            DWORD   dwFlags,
  [out]           PULONG  pulNumLanguages,
  [out, optional] PZZWSTR pwszLanguagesBuffer,
  [in, out]       PULONG  pcchLanguagesBuffer
);