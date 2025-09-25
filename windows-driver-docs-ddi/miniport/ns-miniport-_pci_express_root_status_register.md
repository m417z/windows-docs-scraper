## Description

The **PCI_EXPRESS_ROOT_STATUS_REGISTER** union describes a PCI Express (PCIe) root status register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.PMERequestorId`

A [PCI_EXPRESS_PME_REQUESTOR_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_pme_requestor_id) structure that describes the power management event (PME) requester identifier of the last PME requester.

### `DUMMYSTRUCTNAME.PMEStatus`

A single bit that indicates that a power management event (PME) was asserted by the requester identified by the **PMERequestorId** member.

### `DUMMYSTRUCTNAME.PMEPending`

A single bit that indicates that another power management event (PME) is pending while the **PMEStatus** bit is set.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `AsULONG`

A **ULONG** representation of the contents of the **PCI_EXPRESS_ROOT_STATUS_REGISTER** structure.

## Remarks

The **PCI_EXPRESS_ROOT_STATUS_REGISTER** union is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_ROOT_STATUS_REGISTER** union is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)

[PCI_EXPRESS_PME_REQUESTOR_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_pme_requestor_id)