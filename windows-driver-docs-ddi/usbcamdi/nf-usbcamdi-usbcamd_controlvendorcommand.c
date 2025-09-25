NTSTATUS USBCAMD_ControlVendorCommand(
  [in]                PVOID                      DeviceContext,
  [in]                UCHAR                      Request,
  [in]                USHORT                     Value,
  [in]                USHORT                     Index,
  [in, out, optional] PVOID                      Buffer,
  [in, out]           PULONG                     BufferLength,
  [in]                BOOLEAN                    GetData,
  [in, optional]      PCOMMAND_COMPLETE_FUNCTION CommandComplete,
  [in, optional]      PVOID                      CommandContext
);