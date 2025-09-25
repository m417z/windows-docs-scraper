typedef struct _SCARD_READER_CAPABILITIES {
  ULONG                    SupportedProtocols;
  ULONG                    Reserved;
  ULONG                    ReaderType;
  ULONG                    MechProperties;
  ULONG                    CurrentState;
  ULONG                    Channel;
  struct {
    ULONG Default;
    ULONG Max;
  } CLKFrequency;
  struct {
    ULONG Default;
    ULONG Max;
  } DataRate;
  ULONG                    MaxIFSD;
  ULONG                    PowerMgmtSupport;
  ULONG                    CardConfiscated;
  struct {
    PULONG List;
    UCHAR  Entries;
  } DataRatesSupported;
  _DataRatesSupported      _DataRatesSupported;
  struct {
    PULONG List;
    UCHAR  Entries;
  } CLKFrequenciesSupported;
  _CLKFrequenciesSupported _CLKFrequenciesSupported;
  UCHAR                    Reserved1[100 - sizeof(ULONG)- sizeof(struct _DataRatesSupported)- sizeof(struct _CLKFrequenciesSupported)];
} SCARD_READER_CAPABILITIES, *PSCARD_READER_CAPABILITIES;