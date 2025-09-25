typedef struct _NDIS_GENERIC_OBJECT {
  NDIS_OBJECT_HEADER Header;
  PVOID              Caller;
  PVOID              CallersCaller;
  PDRIVER_OBJECT     DriverObject;
} NDIS_GENERIC_OBJECT, *PNDIS_GENERIC_OBJECT;