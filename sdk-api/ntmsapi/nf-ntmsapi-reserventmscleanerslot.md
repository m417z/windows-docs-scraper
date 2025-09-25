# ReserveNtmsCleanerSlot function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**ReserveNtmsCleanerSlot** function reserves a single slot in a library unit for a drive cleaner cartridge.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpLibrary` [in]

Unique identifier of the library to reserve the cleaner slot.

### `lpSlot` [in]

Unique identifier of the slot that is to be reserved for a cleaner cartridge.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_ALREADY_RESERVED** | Either this slot or another slot in the library has already been reserved for cleaning. To change the cleaner cartridge slot, the currently reserved cleaner slot must be released first, using the [ReleaseNtmsCleanerSlot](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-releasentmscleanerslot) function. |
| **ERROR_DEVICE_NOT_AVAILABLE** | The library is not currently connected. |
| **ERROR_INVALID_HANDLE** | The value that is specified in the *hSession* parameter is not valid. |
| **ERROR_INVALID_SLOT** | Unable to retrieve the slot definition from the database. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_SLOT_FULL** | A cleaner slot is not reserved. The slot specified has media in it. Reservation can only be performed on an empty slot. |
| **ERROR_SLOT_NOT_PRESENT** | A cleaner slot is not reserved. The slot specified is currently not installed in the library. This error occurs if at least one cartridge magazine is missing from the library. |
| **ERROR_SUCCESS** | The function was queued successfully. |

## Remarks

The slot reserved with the
**ReserveNtmsCleanerSlot** function must be present and empty. The library must not already have a slot reserved for a cleaner cartridge.

## See also

[CleanNtmsDrive](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-cleanntmsdrive)

[Cleaner Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[EjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmscleaner)

[InjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-injectntmscleaner)

[ReleaseNtmsCleanerSlot](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-releasentmscleanerslot)