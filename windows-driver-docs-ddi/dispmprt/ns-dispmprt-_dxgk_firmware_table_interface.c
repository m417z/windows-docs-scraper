typedef struct _DXGK_FIRMWARE_TABLE_INTERFACE {
  USHORT                 Size;
  USHORT                 Version;
  PVOID                  Context;
  PINTERFACE_REFERENCE   InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  NTSTATUS(VOID *Context,ULONG ProviderSignature,ULONG BufferSize,VOID *Buffer,ULONG *RequiredSize)              * )(EnumSystemFirmwareTables;
  NTSTATUS(VOID *Context,ULONG ProviderSignature,ULONG TableId,ULONG BufferSize,VOID *Buffer,ULONG *RequiredSize)              * )(ReadSystemFirmwareTable;
} DXGK_FIRMWARE_TABLE_INTERFACE, *PDXGK_FIRMWARE_TABLE_INTERFACE;