FILTER_ATTACH FilterAttach;

NDIS_STATUS FilterAttach(
  [in] NDIS_HANDLE NdisFilterHandle,
  [in] NDIS_HANDLE FilterDriverContext,
  [in] PNDIS_FILTER_ATTACH_PARAMETERS AttachParameters
)
{...}