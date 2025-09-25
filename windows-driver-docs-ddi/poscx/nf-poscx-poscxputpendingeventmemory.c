NTSTATUS PosCxPutPendingEventMemory(
  [in] WDFDEVICE               device,
  [in] ULONG                   deviceInterfaceTag,
  [in] WDFMEMORY               eventMemory,
  [in] POS_CX_EVENT_ATTRIBUTES eventAttr
);