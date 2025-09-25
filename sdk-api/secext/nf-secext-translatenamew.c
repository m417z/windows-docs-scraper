BOOLEAN SEC_ENTRY TranslateNameW(
  [in]      LPCWSTR              lpAccountName,
  [in]      EXTENDED_NAME_FORMAT AccountNameFormat,
  [in]      EXTENDED_NAME_FORMAT DesiredNameFormat,
  [out]     LPWSTR               lpTranslatedName,
  [in, out] PULONG               nSize
);