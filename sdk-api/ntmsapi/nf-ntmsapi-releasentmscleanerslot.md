# ReleaseNtmsCleanerSlot function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**ReleaseNtmsCleanerSlot** function removes an existing slot reservation for a cleaning cartridge. The slot can then be used for data cartridges.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpLibrary` [in]

Unique identifier of the library to release the cleaner slot.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DEVICE_NOT_AVAILABLE** | The library is not currently connected. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is not valid. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_NO_SLOT_RESERVED** | This library has no slot reserved for a cleaner cartridge. |
| **ERROR_SLOT_FULL** | The library has a reserved cleaner cartridge slot but the slot contains a cleaner cartridge (the slot must be empty). Use the [EjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmscleaner) function to eject a cleaner cartridge. |
| **ERROR_SLOT_NOT_PRESENT** | The library has a reserved cleaner cartridge slot, but the specified slot is currently not installed in the library. This error can occur if at least one magazine is missing from the library. |
| **ERROR_SUCCESS** | The function was queued successfully. |

## Remarks

For the
**ReleaseNtmsCleanerSlot** function to succeed, the slot must be present and empty. The library must also have a slot reserved for cleaning.

## See also

[CleanNtmsDrive](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-cleanntmsdrive)

[Cleaner Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[EjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmscleaner)

[InjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-injectntmscleaner)

[ReserveNtmsCleanerSlot](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-reserventmscleanerslot)