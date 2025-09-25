## Description

The **PCI_EXPRESS_ERROR_SOURCE_ID** union describes the identifiers of the first correctable error and the first uncorrectable error that are reported in the PCI Express (PCIe) root error status register.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.CorrectableSourceIdFun`

The function number of the requester that reported the first correctable error.

### `DUMMYSTRUCTNAME.CorrectableSourceIdDev`

The device number of the requester that reported the first correctable error.

### `DUMMYSTRUCTNAME.CorrectableSourceIdBus`

The bus number of the requester that reported the first correctable error.

### `DUMMYSTRUCTNAME.UncorrectableSourceIdFun`

The function number of the requester that reported the first uncorrectable error.

### `DUMMYSTRUCTNAME.UncorrectableSourceIdDev`

The device number of the requester that reported the first uncorrectable error.

### `DUMMYSTRUCTNAME.UncorrectableSourceIdBus`

The bus number of the requester that reported the first uncorrectable error.

### `AsULONG`

A **ULONG** representation of the contents of the **PCI_EXPRESS_ERROR_SOURCE_ID** structure.

## Remarks

The **PCI_EXPRESS_ERROR_SOURCE_ID** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_ERROR_SOURCE_ID** structure is contained in the [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structure.

## See also

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)