BOOL GetUILanguageInfo(
  [in]                DWORD    dwFlags,
  [in]                PCZZWSTR pwmszLanguage,
  [out, optional]     PZZWSTR  pwszFallbackLanguages,
  [in, out, optional] PDWORD   pcchFallbackLanguages,
  [out]               PDWORD   pAttributes
);