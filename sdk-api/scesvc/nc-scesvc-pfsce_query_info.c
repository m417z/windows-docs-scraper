PFSCE_QUERY_INFO PfsceQueryInfo;

SCESTATUS PfsceQueryInfo(
  [in]           SCE_HANDLE sceHandle,
  [in]           SCESVC_INFO_TYPE sceType,
  [in, optional] LPTSTR lpPrefix,
  [in]           BOOL bExact,
  [out]          PVOID *ppvInfo,
  [out]          PSCE_ENUMERATION_CONTEXT psceEnumHandle
)
{...}