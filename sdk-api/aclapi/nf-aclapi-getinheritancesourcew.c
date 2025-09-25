DWORD GetInheritanceSourceW(
  [in]           LPWSTR                pObjectName,
  [in]           SE_OBJECT_TYPE        ObjectType,
  [in]           SECURITY_INFORMATION  SecurityInfo,
  [in]           BOOL                  Container,
  [in, optional] GUID                  **pObjectClassGuids,
  [in]           DWORD                 GuidCount,
  [in]           PACL                  pAcl,
  [in, optional] PFN_OBJECT_MGR_FUNCTS pfnArray,
  [in]           PGENERIC_MAPPING      pGenericMapping,
  [out]          PINHERITED_FROMW      pInheritArray
);