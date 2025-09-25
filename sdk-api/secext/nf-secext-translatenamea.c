BOOLEAN SEC_ENTRY TranslateNameA(
  [in]      LPCSTR               lpAccountName,
  [in]      EXTENDED_NAME_FORMAT AccountNameFormat,
  [in]      EXTENDED_NAME_FORMAT DesiredNameFormat,
  [out]     LPSTR                lpTranslatedName,
  [in, out] PULONG               nSize
);