# GNSS_ERRORINFO structure

## Description

This structure contains GNSS error information.

## Members

### `Size`

Structure size

### `Version`

Version number

### `ErrorCode`

Win32 Error Code associated with the event.

The IHV can pick the error that is most similar to what needs to be reported (for example, E_OUTOFMEMORY). The IHV can also use FACILITY_ITF to create custom errors. For more information, see [Codes in FACILITY_ITF](https://learn.microsoft.com/windows/win32/com/codes-in-facility-itf).

### `IsRecoverable`

If FALSE, the GNSS adapter needs to reset it's state with the GNSS driver.

### `ErrorDescription`

ErrorDescription[256] - Clear-text description of the error (not-localized) that is used for diagnostic purpose only.

### `Unused`

Unused[512] - Padding buffer