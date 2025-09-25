CMAPI CONFIGRET CM_Open_Class_KeyW(
  [in, optional] LPGUID         ClassGuid,
  [in, optional] LPCWSTR        pszClassName,
  [in]           REGSAM         samDesired,
  [in]           REGDISPOSITION Disposition,
  [out]          PHKEY          phkClass,
  [in]           ULONG          ulFlags
);