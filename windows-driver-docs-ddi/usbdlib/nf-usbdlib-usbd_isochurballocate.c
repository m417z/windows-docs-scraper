NTSTATUS USBD_IsochUrbAllocate(
  [in]  USBD_HANDLE USBDHandle,
  [in]  ULONG       NumberOfIsochPackets,
  [out] PURB        *Urb
);