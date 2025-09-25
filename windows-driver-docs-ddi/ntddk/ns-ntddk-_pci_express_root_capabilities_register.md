# _PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER structure (ntddk.h)

## Description

The PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER structure describes a PCI Express (PCIe) root capabilities register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsUSHORT`

A USHORT representation of the contents of the PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER structure.

### `DUMMYSTRUCTNAME.CRSSoftwareVisibility`

A single bit that indicates that the root port is capable of returning configuration request retry status (CRS) completion status to software.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

## Syntax

```cpp
typedef union _PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER {
  struct {
    USHORT CRSSoftwareVisibility  :1;
    USHORT Rsvd  :15;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER, *PPCI_EXPRESS_ROOT_CAPABILITIES_REGISTER;
```

## Remarks

The PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_ROOT_CAPABILITIES_REGISTER structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)