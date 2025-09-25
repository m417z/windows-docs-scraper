# _PCI_EXPRESS_ROOT_STATUS_REGISTER structure (ntddk.h)

## Description

The PCI_EXPRESS_ROOT_STATUS_REGISTER structure describes a PCI Express (PCIe) root status register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_ROOT_STATUS_REGISTER structure.

### `DUMMYSTRUCTNAME.PMEPending`

A single bit that indicates that another power management event (PME) is pending while the **PMEStatus** bit is set.

### `DUMMYSTRUCTNAME.PMERequestorId`

A [PCI_EXPRESS_PME_REQUESTOR_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_pme_requestor_id) structure that describes the power management event (PME) requester identifier of the last PME requester.

### `DUMMYSTRUCTNAME.PMEStatus`

A single bit that indicates that a power management event (PME) was asserted by the requester identified by the **PMERequestorId** member.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

## Syntax

```cpp
typedef union _PCI_EXPRESS_ROOT_STATUS_REGISTER {
  struct {
    ULONG PMERequestorId  :16;
    ULONG PMEStatus  :1;
    ULONG PMEPending  :1;
    ULONG Rsvd  :14;
  };
  ULONG  AsULONG;
} PCI_EXPRESS_ROOT_STATUS_REGISTER, *PPCI_EXPRESS_ROOT_STATUS_REGISTER;
```

## Remarks

The PCI_EXPRESS_ROOT_STATUS_REGISTER structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_ROOT_STATUS_REGISTER structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)

[PCI_EXPRESS_PME_REQUESTOR_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_pme_requestor_id)