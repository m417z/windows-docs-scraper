DXGKCB_POWERRUNTIMECONTROLREQUEST DxgkcbPowerruntimecontrolrequest;

NTSTATUS DxgkcbPowerruntimecontrolrequest(
  [in]           IN_CONST_HANDLE hAdapter,
  [in]           IN LPCGUID PowerControlCode,
  [in, optional] IN PVOID InBuffer,
  [in]           IN SIZE_T InBufferSize,
  [in, optional] OUT PVOID OutBuffer,
  [in]           IN SIZE_T OutBufferSize,
  [out]          OUT PSIZE_T BytesReturned
)
{...}