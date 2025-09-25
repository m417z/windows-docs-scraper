DXGKDDISETPOWERCOMPONENTFSTATE Dxgkddisetpowercomponentfstate;

NTSTATUS Dxgkddisetpowercomponentfstate(
  IN_CONST_HANDLE DriverContext,
  UINT ComponentIndex,
  UINT FState
)
{...}