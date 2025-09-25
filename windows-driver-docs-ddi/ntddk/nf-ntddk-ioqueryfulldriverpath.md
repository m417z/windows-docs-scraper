## Description

The **IoQueryFullDriverPath** routine retrieves the full path name of the binary file that is loaded for the specified driver object. Starting in Windows 10 version 1709, callers may query for driver objects that are not their own, as long as they use proper synchronization to ensure that the DRIVER_OBJECT structure remains valid during the call.

## Parameters

### `DriverObject` [in]

A pointer to a [**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure. If you are calling **IoQueryFullDriverPath** on a computer running a version of Windows 10 earlier than version 1709, this structure is required to be the driver object for the calling driver.

### `FullPath` [out]

A pointer to a caller-allocated [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure. On successful return, this structure contains the path name.

## Return value

**IoQueryFullDriverPath** returns STATUS_SUCCESS if the call successfully fetches the path name. Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| **STATUS_ACCESS_DENIED** | The target driver object does not belong to the caller. This status code is only returned on versions of Windows 10 earlier than 1709. |
| **STATUS_NOT_FOUND** | The driver object has no section (loaded memory image) associated with it. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to perform the requested operation. |

## Remarks

A driver can call this routine to query for the full path name of its binary file, or, starting in Windows 10 version 1709, the full path name of the binary file for another driver.

The caller allocates the [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure pointed to by the *FullPath* parameter, but does not need to initialize this structure. **IoQueryFullDriverPath** assumes that the original contents of this structure are invalid and overwrites them. This routine allocates a string buffer from paged system memory, sets the **Buffer** member of the structure to point to this buffer, and sets the **MaximumLength** and **Buffer** members to describe the buffer and its contents.

The caller is responsible for freeing the storage pointed to by *FullPath*->**Buffer** when the full path string is no longer needed. Typically, the caller frees this storage by calling a routine such as [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool).

## See also

[**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)