## Description

The **WHEA_AER_ENDPOINT_DESCRIPTOR** structure describes a PCI Express (PCIe) endpoint error source.

## Members

### `Type`

The type of error source descriptor. This member is always set to WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_AERENDPOINT.

### `Enabled`

A Boolean value that indicates if the error source is enabled.

### `Reserved`

Reserved for system use.

### `BusNumber`

The endpoint's bus number.

### `Slot`

A [**WHEA_PCI_SLOT_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pci_slot_number) structure that describes the logical PCI slot where the endpoint is located in the system.

### `DeviceControl`

The contents of the endpoint's Device Control register.

### `Flags`

An AER_ENDPOINT_DESCRIPTOR_FLAGS union that indicates which of the members of the **WHEA_AER_ENDPOINT_DESCRIPTOR** structure can be written to by the operating system. The **AER_ENDPOINT_DESCRIPTOR_FLAGS** union is defined as follows:

```cpp
typedef union _AER_ENDPOINT_DESCRIPTOR_FLAGS {
  struct {
    USHORT  UncorrectableErrorMaskRW:1;
    USHORT  UncorrectableErrorSeverityRW:1;
    USHORT  CorrectableErrorMaskRW:1;
    USHORT  AdvancedCapsAndControlRW:1;
    USHORT  Reserved:12;
  };
  USHORT  AsUSHORT;
} AER_ENDPOINT_DESCRIPTOR_FLAGS, *PAER_ENDPOINT_DESCRIPTOR_FLAGS
```

#### UncorrectableErrorMaskRW

A single bit that indicates that the operating system can write to the **UncorrectableErrorMask** member of the **WHEA_AER_ENDPOINT_DESCRIPTOR** structure.

#### UncorrectableErrorSeverityRW

A single bit that indicates that the operating system can write to the **UncorrectableErrorSeverity** member of the **WHEA_AER_ENDPOINT_DESCRIPTOR** structure.

#### CorrectableErrorMaskRW

A single bit that indicates that the operating system can write to the **CorrectableErrorMask** member of the **WHEA_AER_ENDPOINT_DESCRIPTOR** structure.

#### AdvancedCapsAndControlRW

A single bit that indicates that the operating system can write to the **AdvancedCapsAndControl** member of the **WHEA_AER_ENDPOINT_DESCRIPTOR** structure.

#### Reserved

Reserved for system use.

#### AsUSHORT

A USHORT representation of the contents of the **AER_ENDPOINT_DESCRIPTOR_FLAGS** union.

### `UncorrectableErrorMask`

The contents of the endpoint's Uncorrectable Error Mask register.

### `UncorrectableErrorSeverity`

The contents of the endpoint's Uncorrectable Error Severity register.

### `CorrectableErrorMask`

The contents of the endpoint's Correctable Error Mask register.

### `AdvancedCapsAndControl`

The contents of the endpoint's Advanced Error Capabilities and Control register.

## Remarks

A **WHEA_AER_ENDPOINT_DESCRIPTOR** structure is contained within the [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure.

## See also

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_PCI_SLOT_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pci_slot_number)