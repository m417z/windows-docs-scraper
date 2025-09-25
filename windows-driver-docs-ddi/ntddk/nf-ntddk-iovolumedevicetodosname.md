## Description

The **IoVolumeDeviceToDosName** routine returns the MS-DOS path for a specified device object that represents a file system volume.

## Parameters

### `VolumeDeviceObject` [in]

A pointer to a device object that represents a volume device object created by a storage class driver.

### `DosName` [out]

A pointer to a caller-allocated [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure. If the call is successful, **IoVolumeDeviceToDosName** sets the values of the **Length**, **MaximumLength**, and **Buffer** members of this structure. On exit, the **Buffer** member points to a wide-character, null-terminated string that contains the MS-DOS path of the volume device object specified by *VolumeDeviceObject*. For more information, see Remarks.

## Return value

**IoVolumeDeviceToDosName** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return value | Description |
|--|--|
| STATUS_INVALID_PARAMETER | The routine failed due to invalid parameter values passed by the caller. |
| STATUS_INSUFFICIENT_RESOURCES | The routine failed to allocate resources required for this operation. |

## Remarks

**IoVolumeDeviceToDosName** allocates the string buffer pointed to by the **Buffer** member of the [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that the *DosName* parameter points to. After this buffer is no longer required, a caller of this routine should call the [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) routine to free the buffer.

Starting with Windows Vista, you must ensure that APCs are not disabled before calling this routine. The [KeAreAllApcsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keareallapcsdisabled) routine can be used to verify that APCs are not disabled.

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[KeAreAllApcsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keareallapcsdisabled)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)