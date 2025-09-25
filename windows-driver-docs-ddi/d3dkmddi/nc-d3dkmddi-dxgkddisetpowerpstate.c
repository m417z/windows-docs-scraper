DXGKDDISETPOWERPSTATE Dxgkddisetpowerpstate;

NTSTATUS Dxgkddisetpowerpstate(
  IN_CONST_HANDLE DriverContext,
  UINT ComponentIndex,
  UINT RequestedComponentPState
)
{...}