## Description

The **SIGNAL_REG_VALUE** structure represents a RAS (Reliability, Availability, and Serviceability) signal register entry that contains register name, MSR address, and value information.

## Members

### `RegName`

A **UINT8** array that contains the name of the RAS register. The maximum length is defined by `WCS_RAS_REGISTER_NAME_MAX_LENGTH`.

### `MsrAddr`

A **UINT32** value that specifies the Model Specific Register (MSR) address for this RAS signal register.

### `Value`

A **UINT64** value that contains the current value stored in the RAS signal register.

## Remarks

This structure is used as part of the EFI ACPI RAS Signal Table for hardware error reporting and signaling mechanisms.

It's used as an array element within the [**EFI_ACPI_RAS_SIGNAL_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-efi_acpi_ras_signal_table) structure. Each entry represents a specific RAS signal register that can be monitored for hardware error conditions.

This structure is primarily used by the Windows Hardware Error Architecture (WHEA) subsystem for logging RAS table entries through ETW (Event Tracing for Windows) events. The structure allows the system to track and report on specific hardware registers that are relevant for reliability and error detection.

When multiple **SIGNAL_REG_VALUE** entries need to be logged, they may be split across multiple ETW events if the total size exceeds the maximum event size limit.

## See also

[**EFI_ACPI_RAS_SIGNAL_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-efi_acpi_ras_signal_table)