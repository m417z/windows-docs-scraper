typedef struct _IDE_CHANNEL_INTERFACE {
  USHORT            Version;
  UCHAR             ChannelNumber;
  UCHAR             Reserved;
  ULONG             ReservedUlong;
  IDE_HW_INITIALIZE IdeHwInitialize;
  IDE_HW_BUILDIO    IdeHwBuildIo;
  IDE_HW_STARTIO    IdeHwStartIo;
  IDE_HW_INTERRUPT  IdeHwInterrupt;
  IDE_HW_RESET      IdeHwReset;
  IDE_HW_CONTROL    IdeHwControl;
} IDE_CHANNEL_INTERFACE, *PIDE_CHANNEL_INTERFACE;