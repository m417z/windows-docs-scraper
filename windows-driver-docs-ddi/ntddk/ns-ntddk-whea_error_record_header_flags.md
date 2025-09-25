# WHEA_ERROR_RECORD_HEADER_FLAGS structure

## Description

Used in the **Flags** member of the [**WHEA_ERROR_RECORD_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Recovered`

A single bit that indicates that the operating system recovered from the error condition.

### `DUMMYSTRUCTNAME.PreviousError`

A single bit that indicates that the error condition occurred in a previous session of the operating system.

### `DUMMYSTRUCTNAME.Simulated`

A single bit that indicates that the error condition was simulated.

### `DUMMYSTRUCTNAME.DeviceDriver`

The error was reported by a device driver.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `AsULONG`

A ULONG representation of the contents of the WHEA_ERROR_RECORD_HEADER_FLAGS union.

### `DUMMYSTRUCTNAME.CriticalEvent`

### `DUMMYSTRUCTNAME.PersistPfn`

### `DUMMYSTRUCTNAME.SectionsTruncated`

### `DUMMYSTRUCTNAME.RecoveryInProgress`

### `DUMMYSTRUCTNAME.Throttle`

## Remarks

## See also