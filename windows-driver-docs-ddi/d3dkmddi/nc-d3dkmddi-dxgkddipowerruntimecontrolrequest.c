DXGKDDIPOWERRUNTIMECONTROLREQUEST Dxgkddipowerruntimecontrolrequest;

NTSTATUS Dxgkddipowerruntimecontrolrequest(
  IN_CONST_HANDLE DriverContext,
  IN LPCGUID PowerControlCode,
  IN PVOID InBuffer,
  IN SIZE_T InBufferSize,
  OUT PVOID OutBuffer,
  IN SIZE_T OutBufferSize,
  OUT PSIZE_T BytesReturned
)
{...}