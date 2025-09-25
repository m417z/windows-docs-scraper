NTSTATUS RegisterAdapterObjectEx(
  [in] PADAPTER_OBJECT     AdapterObject,
  [in] PDEVICE_DESCRIPTION DeviceDescription,
  [in] ULONG               NumberOfMapRegisters,
  [in] ULONG               MaxMappingsByteCount,
  [in] ULONG               MappingTableStride
);