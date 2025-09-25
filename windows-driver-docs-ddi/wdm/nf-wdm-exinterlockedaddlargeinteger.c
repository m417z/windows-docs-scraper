LARGE_INTEGER ExInterlockedAddLargeInteger(
  [in, out] PLARGE_INTEGER Addend,
  [in]      LARGE_INTEGER  Increment,
  [in, out] PKSPIN_LOCK    Lock
);