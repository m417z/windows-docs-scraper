NTSTATUS USBD_SelectInterfaceUrbAllocateAndBuild(
  [in]  USBD_HANDLE                USBDHandle,
  [in]  USBD_CONFIGURATION_HANDLE  ConfigurationHandle,
        PUSBD_INTERFACE_LIST_ENTRY InterfaceListEntry,
  [out] PURB                       *Urb
);