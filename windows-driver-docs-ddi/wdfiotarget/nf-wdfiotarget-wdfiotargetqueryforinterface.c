NTSTATUS WdfIoTargetQueryForInterface(
  [in]           WDFIOTARGET IoTarget,
  [in]           LPCGUID     InterfaceType,
  [out]          PINTERFACE  Interface,
  [in]           USHORT      Size,
  [in]           USHORT      Version,
  [in, optional] PVOID       InterfaceSpecificData
);