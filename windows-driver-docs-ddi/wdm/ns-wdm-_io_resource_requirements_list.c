typedef struct _IO_RESOURCE_REQUIREMENTS_LIST {
  ULONG            ListSize;
  INTERFACE_TYPE   InterfaceType;
  ULONG            BusNumber;
  ULONG            SlotNumber;
  ULONG            Reserved[3];
  ULONG            AlternativeLists;
  IO_RESOURCE_LIST List[1];
} IO_RESOURCE_REQUIREMENTS_LIST, *PIO_RESOURCE_REQUIREMENTS_LIST;