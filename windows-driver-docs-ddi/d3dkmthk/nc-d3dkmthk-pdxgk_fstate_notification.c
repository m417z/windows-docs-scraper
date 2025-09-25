PDXGK_FSTATE_NOTIFICATION PdxgkFstateNotification;

VOID PdxgkFstateNotification(
  PVOID GraphicsDeviceHandle,
  ULONG ComponentIndex,
  UINT NewFState,
  BOOLEAN PreNotification,
  PVOID PrivateHandle
)
{...}