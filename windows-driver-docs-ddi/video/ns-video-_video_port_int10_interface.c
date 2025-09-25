typedef struct _VIDEO_PORT_INT10_INTERFACE {
  IN USHORT                  Size;
  IN USHORT                  Version;
  OUT PVOID                  Context;
  OUT PINTERFACE_REFERENCE   InterfaceReference;
  OUT PINTERFACE_DEREFERENCE InterfaceDereference;
  OUT PINT10_ALLOCATE_BUFFER Int10AllocateBuffer;
  OUT PINT10_FREE_BUFFER     Int10FreeBuffer;
  OUT PINT10_READ_MEMORY     Int10ReadMemory;
  OUT PINT10_WRITE_MEMORY    Int10WriteMemory;
  OUT PINT10_CALL_BIOS       Int10CallBios;
} VIDEO_PORT_INT10_INTERFACE, *PVIDEO_PORT_INT10_INTERFACE;