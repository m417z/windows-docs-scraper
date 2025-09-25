## Description

The **WHEA_PCIXBUS_ERROR_SECTION** structure describes PCI or PCI-X bus error data.

## Members

### `ValidBits`

A [**WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section_validbits) union that specifies which members of this structure contain valid data.

### `ErrorStatus`

A [**WHEA_ERROR_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_status) structure that contains PCI or PCI-X bus error status data.

This member contains valid data only if the **ValidBits.ErrorStatus** bit is set.

### `ErrorType`

The type of PCI or PCI-X bus error that occurred. Possible values are:

#### PCIXBUS_ERRTYPE_UNKNOWN

An unknown or platform-specific error.

#### PCIXBUS_ERRTYPE_DATAPARITY

A data parity error.

#### PCIXBUS_ERRTYPE_SYSTEM

A system error.

#### PCIXBUS_ERRTYPE_MASTERABORT

A master abort.

#### PCIXBUS_ERRTYPE_BUSTIMEOUT

A bus timeout, or no device is present.

#### PCIXBUS_ERRTYPE_MASTERDATAPARITY

A master data parity error.

#### PCIXBUS_ERRTYPE_ADDRESSPARITY

An address parity error.

#### PCIXBUS_ERRTYPE_COMMANDPARITY

A command parity error.

This member contains valid data only if the **ValidBits.ErrorType** bit is set.

### `BusId`

A WHEA_PCIXBUS_ID union that identifies the bus where the error occurred. The **WHEA_PCIXBUS_ID** union is defined as follows:

```cpp
typedef union _WHEA_PCIXBUS_ID {
  struct {
    UCHAR  BusNumber;
    UCHAR  BusSegment;
  };
  USHORT  AsUSHORT;
} WHEA_PCIXBUS_ID, *PWHEA_PCIXBUS_ID;
```

#### BusNumber

The bus number.

#### BusSegment

The bus segment.

#### AsUSHORT

A USHORT representation of the contents of the **WHEA_PCIXBUS_ID** union.

This member contains valid data only if the **ValidBits.BusId** bit is set.

### `Reserved`

Reserved for system use.

### `BusAddress`

The memory or I/O address on the bus when the error occurred.

This member contains valid data only if the **ValidBits.BusAddress** bit is set.

### `BusData`

The data on the bus when the error occurred.

This member contains valid data only if the **ValidBits.BusData** bit is set.

### `BusCommand`

A WHEA_PCIXBUS_COMMAND union that contains the bus command when the error occurred. The **WHEA_PCIXBUS_COMMAND** union is defined as follows:

```cpp
typedef union _WHEA_PCIXBUS_COMMAND {
  struct {
    ULONGLONG  Command:56;
    ULONGLONG  PCIXCommand:1;
    ULONGLONG  Reserved:7;
  };
  ULONGLONG  AsULONGLONG;
} WHEA_PCIXBUS_COMMAND, *PWHEA_PCIXBUS_COMMAND;
```

#### Command

The PCI or PCI-X bus command.

#### PCIXCommand

A single bit that indicates that the command is a PCI-X command.

#### Reserved

Reserved for system use.

#### AsULONGLONG

A ULONGLONG representation of the contents of the **WHEA_PCIXBUS_COMMAND** union.

This member contains valid data only if the **ValidBits.BusCommand** bit is set.

### `RequesterId`

An identifier that uniquely identifies the requester that is associated with the error.

This member contains valid data only if the **ValidBits.RequesterId** bit is set.

### `CompleterId`

An identifier that uniquely identifies the PCI bus responder that is associated with the error.

This member contains valid data only if the **ValidBits.CompleterId** bit is set.

### `TargetId`

An identifier that uniquely identifies the intended target of the PCI bus command.

This member contains valid data only if the **ValidBits.TargetId** bit is set.

## Remarks

The **WHEA_PCIXBUS_ERROR_SECTION** structure describes the error data that is contained in a PCI/PCI-X bus error section of an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). An error record contains a PCI/PCI-X bus error section only if the **SectionType** member of one of the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describe the error record sections for that error record contains PCIXBUS_ERROR_SECTION_GUID.

## See also

[**WHEA_ERROR_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)

[**WHEA_ERROR_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_status)

[**WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section_validbits)