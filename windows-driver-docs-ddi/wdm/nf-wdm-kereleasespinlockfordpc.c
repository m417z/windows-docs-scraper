VOID KeReleaseSpinLockForDpc(
  [in, out] PKSPIN_LOCK SpinLock,
  [in]      KIRQL       OldIrql
);