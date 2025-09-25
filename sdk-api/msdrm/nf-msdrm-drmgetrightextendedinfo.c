DRMEXPORT HRESULT UDAPICALL DRMGetRightExtendedInfo(
  [in]      DRMPUBHANDLE hRight,
  [in]      UINT         uIndex,
  [in, out] UINT         *puExtendedInfoNameLength,
  [out]     PWSTR        wszExtendedInfoName,
  [in, out] UINT         *puExtendedInfoValueLength,
  [out]     PWSTR        wszExtendedInfoValue
);