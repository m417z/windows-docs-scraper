typedef struct {
  ULONG    Size;
  ULONG    Version;
  NTSTATUS TestResultStatus;
  double   SignalToNoiseRatio;
  double   Frequency;
  BYTE     Unused[512];
} GNSS_CWTESTDATA, *PGNSS_CWTESTDATA;