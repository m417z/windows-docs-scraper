typedef struct _BUS_INTERFACE_STANDARD {
  USHORT                 Size;
  USHORT                 Version;
  PVOID                  Context;
  PINTERFACE_REFERENCE   InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PTRANSLATE_BUS_ADDRESS TranslateBusAddress;
  PGET_DMA_ADAPTER       GetDmaAdapter;
  PGET_SET_DEVICE_DATA   SetBusData;
  PGET_SET_DEVICE_DATA   GetBusData;
} BUS_INTERFACE_STANDARD, *PBUS_INTERFACE_STANDARD;