BOOLEAN AtaPortRegistryChannelSubkeyWriteDeferred(
  [in] PVOID  ChannelExtension,
  [in] UCHAR  ControllerNumber,
  [in] PCHAR  ValueName,
  [in] UCHAR  ValueType,
  [in] PUCHAR Buffer,
       PULONG BufferLength
);