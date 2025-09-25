USBD_STATUS USBD_ValidateConfigurationDescriptor(
  [in]           PUSB_CONFIGURATION_DESCRIPTOR ConfigDesc,
  [in]           ULONG                         BufferLength,
  [in]           USHORT                        Level,
  [out]          PUCHAR                        *Offset,
  [in, optional] ULONG                         Tag
);