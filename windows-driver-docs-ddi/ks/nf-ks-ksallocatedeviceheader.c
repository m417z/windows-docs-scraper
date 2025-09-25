KSDDKAPI NTSTATUS KsAllocateDeviceHeader(
  [out]          KSDEVICE_HEADER       *Header,
  [in]           ULONG                 ItemsCount,
  [in, optional] PKSOBJECT_CREATE_ITEM ItemsList
);