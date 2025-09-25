## Description

The WHEA_RAW_DATA_FORMAT enumeration defines the possible formats that raw hardware error data can be encoded in a hardware error packet.

## Constants

### `WheaRawDataFormatIPFSalRecord`

The raw data in the hardware error packet contains an Itanium processor family system abstraction layer (SAL) error record. For more information about the format of a SAL error record, see the [Intel Itanium Processor Family System Abstraction Layer Specification](https://www.intel.com/content/dam/www/public/us/en/documents/specification-updates/itanium-system-abstraction-layer-specification.pdf).

### `WheaRawDataFormatIA32MCA`

The raw data in the hardware error packet contains an MCA_EXCEPTION structure. For more information about the MCA_EXCEPTION structure, see [HalQuerySystemInformation](https://learn.microsoft.com/previous-versions/windows/hardware/mca/ff540659(v=vs.85)).

### `WheaRawDataFormatIntel64MCA`

The raw data in the hardware error packet contains an MCA_EXCEPTION structure. For more information about the MCA_EXCEPTION structure, see [HalQuerySystemInformation](https://learn.microsoft.com/previous-versions/windows/hardware/mca/ff540659(v=vs.85)).

### `WheaRawDataFormatAMD64MCA`

The raw data in the hardware error packet contains an MCA_EXCEPTION structure. For more information about the MCA_EXCEPTION structure, see [HalQuerySystemInformation](https://learn.microsoft.com/previous-versions/windows/hardware/mca/ff540659(v=vs.85)).

### `WheaRawDataFormatMemory`

The raw data in the hardware error packet contains memory error data. The format of this error data is memory architecture-dependent.

### `WheaRawDataFormatPCIExpress`

The raw data in the hardware error packet contains a [PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability) structure.

### `WheaRawDataFormatNMIPort`

The raw data in the hardware error packet contains the data that was read from the nonmaskable interrupt (NMI) I/O ports by the NMI low-level hardware error handler (LLHEH).

### `WheaRawDataFormatPCIXBus`

The raw data in the hardware error packet contains PCI/PCI-X bus error data. The format of this error data is specific to the implementation.

### `WheaRawDataFormatPCIXDevice`

The raw data in the hardware error packet contains a PCI/PCI-X device error data. The format of this error data is specific to the implementation.

### `WheaRawDataFormatGeneric`

The raw data in the hardware error packet contains a [WHEA_GENERIC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error) structure.

### `WheaRawDataFormatMax`

The maximum number of formats of raw hardware error data.

## Remarks

The [WHEA_ERROR_PACKET_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v1) structure contains a member of type WHEA_RAW_DATA_FORMAT that specifies the format of the raw data that is contained in the hardware error packet.

## See also

[HalQuerySystemInformation](https://learn.microsoft.com/previous-versions/windows/hardware/mca/ff540659(v=vs.85))

[PCI_EXPRESS_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[WHEA_ERROR_PACKET_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v1)

[WHEA_GENERIC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error)