PNEGOTIATE_IEEE_MODE PnegotiateIeeeMode;

NTSTATUS PnegotiateIeeeMode(
  [in] PVOID Context,
  [in] USHORT ModeMaskFwd,
  [in] USHORT ModeMaskRev,
  [in] PARALLEL_SAFETY ModeSafety,
  [in] BOOLEAN IsForward
)
{...}