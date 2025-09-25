## Description

The **WHEA_NMI_ERROR_SECTION** structure describes nonmaskable interrupt (NMI) error data.

## Members

### `Data`

An 8-byte data buffer that contains the data that was read from the NMI I/O ports by the NMI low-level hardware error handler (LLHEH).

### `Flags`

A **WHEA_NMI_ERROR__SECTION_FLAGS** union that describes the source of the NMI error. The **WHEA_NMI_ERROR_FLAGS** union is defined as follows:

```cpp
typedef union _WHEA_NMI_ERROR_SECTION_FLAGS {
  struct {
    ULONG  HypervisorError:1;
    ULONG  Reserved:31;
  };
  ULONG  AsULONG;
} WHEA_NMI_ERROR_SECTION_FLAGS, *PWHEA_NMI_ERROR_SECTION_FLAGS;
```

#### HypervisorError

A hypervisor error has occurred.

#### Reserved

Reserved for system use.

#### AsULONG

A **ULONG** representation of the contents of the **WHEA_NMI_ERROR_SECTION_FLAGS** union.

## Remarks

The WHEA_NMI_ERROR_SECTION structure describes the error data contained in a nonmaskable interrupt (NMI) error section of an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). An error record contains an NMI error section only if the **SectionType** member of one of the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describe the error record sections for that error record contains NMI_SECTION_GUID.

## See also

[**WHEA_ERROR_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)