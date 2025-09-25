ULONG ExInterlockedAddUlong(
  [in, out] PULONG      Addend,
  [in]      ULONG       Increment,
  [in, out] PKSPIN_LOCK Lock
);