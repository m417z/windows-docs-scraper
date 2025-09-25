# _PCI_EXPRESS_PME_REQUESTOR_ID structure (ntddk.h)

## Description

The PCI_EXPRESS_PME_REQUESTOR_ID structure describes the identifier of the requester of a power management event (PME).

## Members

### `DUMMYSTRUCTNAME`

### `AsUSHORT`

A USHORT representation of the contents of the PCI_EXPRESS_PME_REQUESTOR_ID structure.

### `DUMMYSTRUCTNAME.BusNumber`

The bus number of the requester.

### `DUMMYSTRUCTNAME.DeviceNumber`

The device number of the requester.

### `DUMMYSTRUCTNAME.FunctionNumber`

The function number of the requester.

## Syntax

```cpp
typedef union _PCI_EXPRESS_PME_REQUESTOR_ID {
  struct {
    USHORT FunctionNumber  :3;
    USHORT DeviceNumber  :5;
    USHORT BusNumber  :3;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_PME_REQUESTOR_ID, *PPCI_EXPRESS_PME_REQUESTOR_ID;
```

## Remarks

The PCI_EXPRESS_PME_REQUESTOR_ID structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_PME_REQUESTOR_ID structure is contained in the **PMERequestorId** member of the [PCI_EXPRESS_ROOT_STATUS_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_root_status_register) structure.

## See also

[PCI_EXPRESS_ROOT_STATUS_REGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_root_status_register)