ULONG StorPortEtwLogByteStream(
  [in]           PVOID                      HwDeviceExtension,
  [in, optional] PSTOR_ADDRESS              Address,
  [in]           STORPORT_ETW_EVENT_CHANNEL EventChannel,
  [in]           ULONG                      EventId,
  [in]           PWSTR                      EventDescription,
  [in]           ULONGLONG                  EventKeywords,
  [in]           STORPORT_ETW_LEVEL         EventLevel,
  [in]           STORPORT_ETW_EVENT_OPCODE  EventOpcode,
  [in]           USHORT                     DataLength,
  [in]           PUCHAR                     Data
);