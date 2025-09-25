## Description

The **WHEA_PCIXDEVICE_ERROR_SECTION** structure describes PCI or PCI-X device error data.

## Members

### `ValidBits`

A [**WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section_validbits) union that specifies which members of this structure contain valid data.

### `ErrorStatus`

A [**WHEA_ERROR_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_status) structure that contains PCI or PCI-X device error status data.

This member contains valid data only if the **ValidBits.ErrorStatus** bit is set.

### `IdInfo`

A WHEA_PCIXDEVICE_ID structure that contains data that identifies the PCI or PCI-X device. The **WHEA_PCIXDEVICE_ID** structure is defined as follows:

```cpp
typedef struct _WHEA_PCIXDEVICE_ID {
  USHORT  VendorId;
  USHORT  DeviceId;
  ULONG  ClassCode:24;
  ULONG  FunctionNumber:8;
  ULONG  DeviceNumber:8;
  ULONG  BusNumber:8;
  ULONG  SegmentNumber:8;
  ULONG  Reserved1:8;
  ULONG  Reserved2;
} WHEA_PCIXDEVICE_ID, *PWHEA_PCIXDEVICE_ID;
```

#### VendorId

The vendor ID of the device.

#### DeviceId

The device ID of the device.

#### ClassCode

The class code of the device.

#### FunctionNumber

The function number of the device on the bus.

#### DeviceNumber

The device number of the device on the bus.

#### BusNumber

The number of the bus that contains the device.

#### SegmentNumber

The number of the bus segment that contains the device.

#### Reserved1

Reserved for system use.

#### Reserved2

Reserved for system use.

This member contains valid data only if the **ValidBits.IdInfo** bit is set.

### `MemoryNumber`

The number of memory mapped register address/data pair values from the PCI device that are included in the **RegisterDataPairs** member.

This member contains valid data only if the **ValidBits.MemoryNumber** bit is set.

### `IoNumber`

The number of I/O mapped register address/data pair values from the PCI device that are included in the **RegisterDataPairs** member.

This member contains valid data only if the **ValidBits.IoNumber** bit is set.

### `RegisterDataPairs`

An array of **WHEA_PCIXDEVICE_REGISTER_PAIR** structures that contains the register address/data pair values for the PCI device. The **WHEA_PCIXDEVICE_REGISTER_PAIR** structure is defined as follows:

```cpp
typedef struct WHEA_PCIXDEVICE_REGISTER_PAIR {
  ULONGLONG  Register;
  ULONGLONG  Data;
} WHEA_PCIXDEVICE_REGISTER_PAIR, *PWHEA_PCIXDEVICE_REGISTER_PAIR;
```

#### Register

The address of the register.

#### Data

The data contained in the register.

This member contains valid data only if the **ValidBits.RegisterDataPairs** bit is set.

## Remarks

The WHEA_PCIXDEVICE_ERROR_SECTION structure describes the error data that is contained in a PCI/PCI-X device error section of an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). An error record contains a PCI/PCI-X device error section only if the **SectionType** member of one of the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describe the error record sections for that error record contains PCIXBUS_ERROR_SECTION_GUID.

## See also

[**WHEA_ERROR_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)

[**WHEA_ERROR_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_status)

[**WHEA_PCIXDEVICE_ERROR_SECTION_VALIDBITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section_validbits)