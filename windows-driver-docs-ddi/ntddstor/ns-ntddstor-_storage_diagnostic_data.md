# STORAGE_DIAGNOSTIC_DATA structure

## Description

**STORAGE_DIAGNOSTIC_DATA** describes diagnostic data about the storage driver stack. It is provided in the output buffer of an [**IOCTL_STORAGE_DIAGNOSTIC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_diagnostic) request.

## Members

### `Version`

Version of this structure. Set to ```sizeof(STORAGE_DIAGNOSTIC_DATA)```.

### `Size`

Specifies the whole size of the structure and the associated data buffer, in bytes.

### `ProviderId`

Specifies the GUID of a diagnostic data provider.

### `BufferSize`

The driver should set **BufferSize** as follows:

* If the request is successful, set with the returned buffer size of **DiagnosticDataBuffer**.
* If the request failed because of buffer too small, set with the required buffer size for a **DiagnosticDataBuffer** needed by the provider.
* If the request failed for any other reason, clear to zero.

### `Reserved`

Reserved for future use.

### `DiagnosticDataBuffer`

Specifies the Diagnostic data buffer.

## See also

[**IOCTL_STORAGE_DIAGNOSTIC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_diagnostic)

[**STORAGE_DIAGNOSTIC_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_diagnostic_request)