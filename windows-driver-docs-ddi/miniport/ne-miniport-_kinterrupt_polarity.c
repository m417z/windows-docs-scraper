typedef enum _KINTERRUPT_POLARITY {
  InterruptPolarityUnknown,
  InterruptActiveHigh,
  InterruptRisingEdge,
  InterruptActiveLow,
  InterruptFallingEdge,
  InterruptActiveBoth,
  InterruptActiveBothTriggerLow,
  InterruptActiveBothTriggerHigh
} KINTERRUPT_POLARITY, *PKINTERRUPT_POLARITY;