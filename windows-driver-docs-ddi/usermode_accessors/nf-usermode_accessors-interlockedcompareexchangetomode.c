LONG InterlockedCompareExchangeToMode(
  LONG volatile   *Destination,
  LONG            ExChange,
  LONG            Comperand,
  KPROCESSOR_MODE Mode
);