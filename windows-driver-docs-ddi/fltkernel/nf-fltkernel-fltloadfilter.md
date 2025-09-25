# FltLoadFilter function

## Description

The **FltLoadFilter** routine dynamically loads a minifilter driver into the currently running system.

## Parameters

### `FilterName` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure containing the service name for the minifilter driver.

## Return value

**FltLoadFilter** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_DRIVER_FAILED_PRIOR_UNLOAD** | The minifilter driver could not be loaded because a previous version of the driver is still in memory. This is an error code. |
| **STATUS_FAILED_DRIVER_ENTRY** | The minifilter driver's **DriverEntry** routine returned an NTSTATUS value that was not a success code. This is an error code. |
| **STATUS_IMAGE_ALREADY_LOADED** | The minifilter driver is already running. This is an error code. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | No matching minifilter driver was found. This is an error code. |

## Remarks

A minifilter driver that has a dependency on another minifilter driver can load that minifilter driver by calling **FltLoadFilter**.

To unload the supporting minifilter driver, call [FltUnloadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltunloadfilter).

## See also

[FltUnloadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltunloadfilter)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)