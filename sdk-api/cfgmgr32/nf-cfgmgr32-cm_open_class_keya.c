CMAPI CONFIGRET CM_Open_Class_KeyA(
  [in, optional] LPGUID         ClassGuid,
  [in, optional] LPCSTR         pszClassName,
  [in]           REGSAM         samDesired,
  [in]           REGDISPOSITION Disposition,
  [out]          PHKEY          phkClass,
  [in]           ULONG          ulFlags
);