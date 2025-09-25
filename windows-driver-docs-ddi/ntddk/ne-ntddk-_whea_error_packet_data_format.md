## Description

The WHEA_ERROR_PACKET_DATA_FORMAT enumeration defines the raw hardware error data format in a hardware error packet.

## Constants

### `WheaDataFormatIPFSalRecord`

The raw data in the hardware error packet contains an Itanium processor family system abstraction layer (SAL) error record. For more information about the format of a SAL error record, see the [Intel Itanium Processor Family System Abstraction Layer Specification](https://www.intel.com/content/dam/www/public/us/en/documents/specification-updates/itanium-system-abstraction-layer-specification.pdf).

### `WheaDataFormatXPFMCA`

The raw data in the hardware error packet is formatted as an MCA_EXCEPTION structure. For more information about the MCA_EXCEPTION structure, see [HalQuerySystemInformation](https://learn.microsoft.com/previous-versions/windows/hardware/mca/ff540659(v=vs.85)).

### `WheaDataFormatMemory`

The raw data in the hardware error packet contains memory error data. The format of this error data is dependent on the memory architecture.

### `WheaDataFormatPCIExpress`

The raw data in the hardware error packet is formatted as a [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability) structure.

### `WheaDataFormatNMIPort`

The raw data in the hardware error packet contains the data that was read from the nonmaskable interrupt (NMI) I/O ports by the NMI low-level hardware error handler (LLHEH). The format of this error data is specific to the implementation.

### `WheaDataFormatPCIXBus`

The raw data in the hardware error packet contains PCI/PCI-X bus error data. The format of this error data is specific to the implementation.

### `WheaDataFormatPCIXDevice`

The raw data in the hardware error packet contains a PCI/PCI-X device error data. The format of this error data is specific to the implementation.

### `WheaDataFormatGeneric`

The raw data in the hardware error packet is formatted as a [WHEA_GENERIC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error) structure.

### `WheaDataFormatMax`

The maximum number of formats of raw hardware error data.

## Remarks

The [WHEA_ERROR_PACKET_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2) structure contains a member of type WHEA_ERROR_PACKET_DATA_FORMAT that specifies the format of the raw data that is contained in the hardware error packet.

## See also

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[WHEA_ERROR_PACKET_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2)

[WHEA_GENERIC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error)