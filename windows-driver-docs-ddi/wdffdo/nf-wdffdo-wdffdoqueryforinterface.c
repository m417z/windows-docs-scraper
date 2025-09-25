NTSTATUS WdfFdoQueryForInterface(
  [in]           WDFDEVICE  Fdo,
  [in]           LPCGUID    InterfaceType,
  [out]          PINTERFACE Interface,
  [in]           USHORT     Size,
  [in]           USHORT     Version,
  [in, optional] PVOID      InterfaceSpecificData
);