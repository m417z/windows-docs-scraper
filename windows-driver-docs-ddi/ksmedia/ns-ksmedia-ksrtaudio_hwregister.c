typedef struct {
  PVOID     Register;
  ULONG     Width;
  ULONGLONG Numerator;
  ULONGLONG Denominator;
  ULONG     Accuracy;
} KSRTAUDIO_HWREGISTER, *PKSRTAUDIO_HWREGISTER;