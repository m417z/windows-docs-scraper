NTSTATUS IoEnumerateKsrPersistentMemoryEx(
  PDRIVER_OBJECT                            DriverObject,
  PDEVICE_OBJECT                            PhysicalDeviceObject,
  PUNICODE_STRING                           PhysicalDeviceId,
  PIO_PERSISTED_MEMORY_ENUMERATION_CALLBACK Callback,
  PVOID                                     CallbackContext
);