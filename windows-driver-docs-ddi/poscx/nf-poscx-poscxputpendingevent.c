NTSTATUS PosCxPutPendingEvent(
  [in] WDFDEVICE               device,
  [in] ULONG                   deviceInterfaceTag,
  [in] ULONG                   eventType,
  [in] size_t                  rawEventDataSize,
       PVOID                   rawEventDataPtr,
  [in] POS_CX_EVENT_ATTRIBUTES eventAttr
);