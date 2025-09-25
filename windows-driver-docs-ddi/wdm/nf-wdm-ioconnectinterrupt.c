NTSTATUS IoConnectInterrupt(
  [out]          PKINTERRUPT       *InterruptObject,
  [in]           PKSERVICE_ROUTINE ServiceRoutine,
  [in, optional] PVOID             ServiceContext,
  [in, optional] PKSPIN_LOCK       SpinLock,
  [in]           ULONG             Vector,
  [in]           KIRQL             Irql,
  [in]           KIRQL             SynchronizeIrql,
  [in]           KINTERRUPT_MODE   InterruptMode,
  [in]           BOOLEAN           ShareVector,
  [in]           KAFFINITY         ProcessorEnableMask,
  [in]           BOOLEAN           FloatingSave
);