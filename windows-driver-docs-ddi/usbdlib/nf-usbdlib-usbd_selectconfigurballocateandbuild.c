NTSTATUS USBD_SelectConfigUrbAllocateAndBuild(
  [in]  USBD_HANDLE                   USBDHandle,
  [in]  PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
  [in]  PUSBD_INTERFACE_LIST_ENTRY    InterfaceList,
  [out] PURB                          *Urb
);