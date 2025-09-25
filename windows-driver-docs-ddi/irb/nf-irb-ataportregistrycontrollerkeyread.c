BOOLEAN AtaPortRegistryControllerKeyRead(
  [in]            PVOID  ChannelExtension,
  [in]            UCHAR  ControllerNumber,
  [in]            PCHAR  ValueName,
  [in]            UCHAR  ValueType,
  [out, optional] PUCHAR Buffer,
                  PULONG BufferLength
);