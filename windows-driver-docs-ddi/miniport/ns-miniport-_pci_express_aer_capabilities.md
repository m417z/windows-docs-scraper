## Description

The **PCI_EXPRESS_AER_CAPABILITIES** union describes a PCI Express (PCIe) advanced error capabilities and control register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.FirstErrorPointer`

The bit position of the first error that was reported in the PCIe uncorrectable error status register.

### `DUMMYSTRUCTNAME.ECRCGenerationCapable`

A single bit that indicates that the device is capable of generating end-to-end cyclic redundancy checks (ECRC).

### `DUMMYSTRUCTNAME.ECRCGenerationEnable`

A single bit that indicates that ECRC generation is enabled.

### `DUMMYSTRUCTNAME.ECRCCheckCapable`

A single bit that indicates that the device is capable of checking ECRC.

### `DUMMYSTRUCTNAME.ECRCCheckEnable`

A single bit that indicates that ECRC checking is enabled.

### `DUMMYSTRUCTNAME.MultipleHeaderRecordingCapable`

Defines the **ULONG** member **MultipleHeaderRecordingCapable**.

### `DUMMYSTRUCTNAME.MultipleHeaderRecordingEnable`

Defines the **ULONG** member **MultipleHeaderRecordingEnable**.

### `DUMMYSTRUCTNAME.TlpPrefixLogPresent`

Defines the **ULONG** member **TlpPrefixLogPresent**.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for future use.

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_AER_CAPABILITIES structure.

## Remarks

The PCI_EXPRESS_AER_CAPABILITIES structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_AER_CAPABILITIES structure is contained in the [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), and [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structures.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)