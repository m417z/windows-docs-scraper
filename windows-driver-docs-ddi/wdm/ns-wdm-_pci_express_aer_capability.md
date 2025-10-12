## Description

The **PCI_EXPRESS_AER_CAPABILITY** structure describes a PCI Express (PCIe) advanced error reporting capability structure.

## Members

### `Header`

A [**PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_enhanced_capability_header) structure that describes the header for this structure.

### `UncorrectableErrorStatus`

A [**PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_uncorrectable_error_status) structure that describes the PCIe uncorrectable error status register of the PCIe AER capability structure.

### `UncorrectableErrorMask`

A [**PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_uncorrectable_error_mask) structure that describes the PCIe uncorrectable error mask register of the PCIe AER capability structure.

### `UncorrectableErrorSeverity`

A [**PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_uncorrectable_error_severity) structure that describes the PCIe uncorrectable error severity register of the PCIe AER capability structure.

### `CorrectableErrorStatus`

A [**PCI_EXPRESS_CORRECTABLE_ERROR_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_correctable_error_status) structure that describes the PCIe correctable error status register of the PCIe AER capability structure.

### `CorrectableErrorMask`

A [**PCI_EXPRESS_CORRECTABLE_ERROR_MASK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_correctable_error_mask) structure that describes the PCIe correctable error mask register of the PCIe AER capability structure.

### `CapabilitiesAndControl`

A [**PCI_EXPRESS_AER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capabilities) structure that describes the PCIe advanced error capabilities and control register of the PCIe AER capability structure.

### `HeaderLog`

An array of four 32-bit values that together contain the header for the transaction layer packet (TLP) that corresponds to a detected error.

Within each 32-bit value in the array, the bytes of the TLP are in big-endian byte order.

### `SecUncorrectableErrorStatus`

A [**PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_sec_uncorrectable_error_status) structure that describes the PCIe secondary uncorrectable error status register of the PCIe AER capability structure.

### `SecUncorrectableErrorMask`

A [**PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_sec_uncorrectable_error_mask) structure that describes the PCIe secondary uncorrectable error mask register of the PCIe AER capability structure.

### `SecUncorrectableErrorSeverity`

A [**PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_sec_uncorrectable_error_severity) structure that describes the PCIe secondary uncorrectable error severity register of the PCIe AER capability structure.

### `SecCapabilitiesAndControl`

A [**PCI_EXPRESS_SEC_AER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_sec_aer_capabilities) structure that describes the PCIe secondary error capabilities and control register of the PCIe AER capability structure.

### `SecHeaderLog`

An array of four 32-bit values that together contain the header for the transaction on the secondary interface that generated an error.

## Syntax

```cpp
typedef struct _PCI_EXPRESS_AER_CAPABILITY {
  PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER       Header;
  PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS       UncorrectableErrorStatus;
  PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK         UncorrectableErrorMask;
  PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY     UncorrectableErrorSeverity;
  PCI_EXPRESS_CORRECTABLE_ERROR_STATUS         CorrectableErrorStatus;
  PCI_EXPRESS_CORRECTABLE_ERROR_MASK           CorrectableErrorMask;
  PCI_EXPRESS_AER_CAPABILITIES                 CapabilitiesAndControl;
  ULONG                                        HeaderLog[4];
  PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_STATUS   SecUncorrectableErrorStatus;
  PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_MASK     SecUncorrectableErrorMask;
  PCI_EXPRESS_SEC_UNCORRECTABLE_ERROR_SEVERITY SecUncorrectableErrorSeverity;
  PCI_EXPRESS_SEC_AER_CAPABILITIES             SecCapabilitiesAndControl;
  ULONG                                        SecHeaderLog[4];
} PCI_EXPRESS_AER_CAPABILITY, *PPCI_EXPRESS_AER_CAPABILITY;
```

## Remarks

PCIe bridge devices use the [**PCI_EXPRESS_BRIDGE_AER_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability) structure instead of the PCI_EXPRESS_AER_CAPABILITY structure to describe the PCIe advanced error reporting capability structure.

Root ports and root complex event collectors use the [**PCI_EXPRESS_ROOTPORT_AER_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability) structure instead of the PCI_EXPRESS_AER_CAPABILITY structure to describe the PCIe advanced error reporting capability structure.

For additional information about the PCIe advanced error reporting capability structure, see the [PCI Express Specification](https://pcisig.com/specifications/pciexpress/).

## See also

[**PCI_EXPRESS_CORRECTABLE_ERROR_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_correctable_error_status)

[**PCI_EXPRESS_UNCORRECTABLE_ERROR_SEVERITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_uncorrectable_error_severity)

[**PCI_EXPRESS_UNCORRECTABLE_ERROR_MASK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_uncorrectable_error_mask)

[**PCI_EXPRESS_AER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capabilities)

[**PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_enhanced_capability_header)

[**PCI_EXPRESS_BRIDGE_AER_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)

[**PCI_EXPRESS_UNCORRECTABLE_ERROR_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_uncorrectable_error_status)

[**PCI_EXPRESS_ROOTPORT_AER_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)

[**PCI_EXPRESS_CORRECTABLE_ERROR_MASK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_correctable_error_mask)