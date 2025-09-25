PGET_LINK_POSITION_REGISTER PgetLinkPositionRegister;

NTSTATUS PgetLinkPositionRegister(
  [in]  PVOID _context,
  [in]  HANDLE Handle,
  [out] PULONG *Position
)
{...}