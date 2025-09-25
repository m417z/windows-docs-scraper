typedef struct _IO_RESOURCE_LIST {
  USHORT                 Version;
  USHORT                 Revision;
  ULONG                  Count;
  IO_RESOURCE_DESCRIPTOR Descriptors[1];
} IO_RESOURCE_LIST, *PIO_RESOURCE_LIST;