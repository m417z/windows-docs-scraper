# _PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER structure (miniport.h)

## Description

The PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER structure describes the header for a PCI Express (PCIe) extended capability structure.

## Members

### `CapabilityID`

The extended capability identifier. Possible values are:

#### PCI_EXPRESS_ADVANCED_ERROR_REPORTING_CAP_ID

Advanced error reporting capability

#### PCI_EXPRESS_VIRTUAL_CHANNEL_CAP_ID

Virtual channel capability

#### PCI_EXPRESS_DEVICE_SERIAL_NUMBER_CAP_ID

Device serial number capability

#### PCI_EXPRESS_POWER_BUDGETING_CAP_ID

Power budgeting capability

#### PCI_EXPRESS_RC_LINK_DECLARATION_CAP_ID

Root complex link declaration capability

#### PCI_EXPRESS_RC_INTERNAL_LINK_CONTROL_CAP_ID

Root complex internal link control capability

#### PCI_EXPRESS_RC_EVENT_COLLECTOR_ENDPOINT_ASSOCIATION_CAP_ID

Root complex event collector endpoint association capability

#### PCI_EXPRESS_MFVC_CAP_ID

Multi-function virtual channel capability

#### PCI_EXPRESS_VC_AND_MFVC_CAP_ID

Virtual channel and multi-function virtual channel capability

#### PCI_EXPRESS_RCRB_HEADER_CAP_ID

Root complex register block header capability

### `Version`

The version of the extended capability structure. This member should be set to one for extended capability structures that are based on version 1.1 of the *PCIe Specification*.

### `Next`

The offset in PCIe device configuration space to the next PCIe capability structure in the linked list of capabilities. If this is the last PCIe capability structure in the list, this member is set to zero.

## Syntax

```cpp
typedef struct _PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER {
  USHORT CapabilityID;
  USHORT Version  :4;
  USHORT Next  :12;
} PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER, *PPCI_EXPRESS_ENHANCED_CAPABILITY_HEADER;
```

## Remarks

The PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_ENHANCED_CAPABILITY_HEADER is included at the beginning of every extended capability structure. Microsoft defines structures for the advanced error reporting capability ([PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability), [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability), or [PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)) and the serial number capability ([PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_serial_number_capability)).

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[PCI_EXPRESS_ROOTPORT_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)

[PCI_EXPRESS_SERIAL_NUMBER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_serial_number_capability)