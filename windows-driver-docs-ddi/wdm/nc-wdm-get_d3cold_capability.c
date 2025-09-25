GET_D3COLD_CAPABILITY GetD3coldCapability;

NTSTATUS GetD3coldCapability(
  [in, optional] PVOID Context,
  [out]          PBOOLEAN D3ColdSupported
)
{...}