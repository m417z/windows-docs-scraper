## Description

The **WHEA_AER_BRIDGE_DESCRIPTOR** structure describes a PCI Express (PCIe) bridge error source.

## Members

### `Type`

The type of error source descriptor. This member is always set to WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_AERBRIDGE.

### `Enabled`

A Boolean value that indicates if the error source is enabled.

### `Reserved`

Reserved for system use.

### `BusNumber`

The bridge's primary bus number.

### `Slot`

A [**WHEA_PCI_SLOT_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pci_slot_number) structure that describes the logical PCI slot where the bridge is located in the system.

### `DeviceControl`

The contents of the bridge's Device Control register.

### `Flags`

An **AER_BRIDGE_DESCRIPTOR_FLAGS** union that indicates which of the members of the **WHEA_AER_BRIDGE_DESCRIPTOR** structure can be written to by the operating system. The AER_BRIDGE_DESCRIPTOR_FLAGS union is defined as follows:

```cpp
typedef union _AER_BRIDGE_DESCRIPTOR_FLAGS {
  struct {
    USHORT  UncorrectableErrorMaskRW:1;
    USHORT  UncorrectableErrorSeverityRW:1;
    USHORT  CorrectableErrorMaskRW:1;
    USHORT  AdvancedCapsAndControlRW:1;
    USHORT  SecondaryUncorrectableErrorMaskRW:1;
    USHORT  SecondaryUncorrectableErrorSevRW:1;
    USHORT  SecondaryCapsAndControlRW:1;
    USHORT  Reserved:9;
  };
  USHORT  AsUSHORT;
} AER_BRIDGE_DESCRIPTOR_FLAGS, *PAER_BRIDGE_DESCRIPTOR_FLAGS
```

#### UncorrectableErrorMaskRW

A single bit that indicates that the operating system can write to the **UncorrectableErrorMask** member of the **WHEA_AER_BRIDGE_DESCRIPTOR** structure.

#### UncorrectableErrorSeverityRW

A single bit that indicates that the operating system can write to the **UncorrectableErrorSeverity** member of the **WHEA_AER_BRIDGE_DESCRIPTOR** structure.

#### CorrectableErrorMaskRW

A single bit that indicates that the operating system can write to the **CorrectableErrorMask** member of the **WHEA_AER_BRIDGE_DESCRIPTOR** structure.

#### AdvancedCapsAndControlRW

A single bit that indicates that the operating system can write to the **AdvancedCapsAndControl** member of the **WHEA_AER_BRIDGE_DESCRIPTOR** structure.

#### SecondaryUncorrectableErrorMaskRW

A single bit that indicates that the operating system can write to the **SecondaryUncorrectableErrorMask** member of the **WHEA_AER_BRIDGE_DESCRIPTOR** structure.

#### SecondaryUncorrectableErrorSevRW

A single bit that indicates that the operating system can write to the **SecondaryUncorrectableErrorSev** member of the **WHEA_AER_BRIDGE_DESCRIPTOR** structure.

#### SecondaryCapsAndControlRW

A single bit that indicates that the operating system can write to the **SecondaryCapsAndControl** member of the **WHEA_AER_BRIDGE_DESCRIPTOR** structure.

#### Reserved

Reserved for system use.

#### AsUSHORT

A USHORT representation of the contents of the **AER_ROOTPORT_DESCRIPTOR_FLAGS** union.

### `UncorrectableErrorMask`

The contents of the bridge's Uncorrectable Error Mask register.

### `UncorrectableErrorSeverity`

The contents of the bridge's Uncorrectable Error Severity register.

### `CorrectableErrorMask`

The contents of the bridge's Correctable Error Mask register.

### `AdvancedCapsAndControl`

The contents of the bridge's Advanced Error Capabilities and Control register.

### `SecondaryUncorrectableErrorMask`

The contents of the bridge's Secondary Uncorrectable Error Mask register.

### `SecondaryUncorrectableErrorSev`

The contents of the bridge's Secondary Uncorrectable Error Severity register.

### `SecondaryCapsAndControl`

The contents of the bridge's Secondary Error Capabilities and Control register.

## Remarks

A **WHEA_AER_BRIDGE_DESCRIPTOR** structure is contained within the [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure.

## See also

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_PCI_SLOT_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pci_slot_number)