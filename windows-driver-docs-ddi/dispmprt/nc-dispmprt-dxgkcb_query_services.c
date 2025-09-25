DXGKCB_QUERY_SERVICES DxgkcbQueryServices;

NTSTATUS DxgkcbQueryServices(
  [in]      HANDLE DeviceHandle,
  [in]      DXGK_SERVICES ServicesType,
  [in, out] PINTERFACE Interface
)
{...}