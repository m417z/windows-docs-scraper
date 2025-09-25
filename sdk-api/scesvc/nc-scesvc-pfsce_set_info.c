PFSCE_SET_INFO PfsceSetInfo;

SCESTATUS PfsceSetInfo(
  [in]           SCE_HANDLE sceHandle,
  [in]           SCESVC_INFO_TYPE sceType,
  [in, optional] LPTSTR lpPrefix,
  [in]           BOOL bExact,
  [in]           PVOID pvInfo
)
{...}