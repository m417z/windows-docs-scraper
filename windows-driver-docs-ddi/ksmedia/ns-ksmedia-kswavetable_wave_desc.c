typedef struct {
  KSIDENTIFIER Identifier;
  ULONG        Size;
  BOOL         Looped;
  ULONG        LoopPoint;
  BOOL         InROM;
  KSDATAFORMAT Format;
} KSWAVETABLE_WAVE_DESC, *PKSWAVETABLE_WAVE_DESC;