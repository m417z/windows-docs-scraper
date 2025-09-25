# InjectNtmsCleaner function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**InjectNtmsCleaner** function allows a cleaner cartridge to be inserted into the specified library unit.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpLibrary` [in]

Unique identifier of a library object.

### `lpInjectOperation` [in, out]

GUID of the insert process library operation. If *dwAction* is NTMS_INJECT_START, this parameter receives the GUID for the operation. If *dwAction* is NTMS_INJECT_STOP, this parameter must be set to the GUID for the operation to be stopped.

### `dwNumberOfCleansLeft` [out]

Number of cleaning cycles left on the inserted cleaning cartridge.

### `dwAction` [in]

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_INJECT_START** | Start the insertion with either the NTMS_IEPORT or the NTMS_IEDOOR object. A single cleaner cartridge should be inserted. If the NTMS_IEDOOR object is used, no inventory will be performed on the library. |
| **NTMS_INJECT_STOP** | Terminates the insertion prior to the time-out event lapsing. (For libraries with ports only.) |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access to at least one RSM object is denied. |
| **ERROR_DEVICE_NOT_AVAILABLE** | The library is not currently connected. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is not valid. |
| **ERROR_INVALID_LIBRARY** | Unable to retrieve the library definition from the database. |
| **ERROR_LIBRARY_OFFLINE** | The library must be online for a cleaner cartridge to be inserted. |
| **ERROR_NO_SLOT_SET** | This library has no slot reserved as a cleaner slot. |
| **ERROR_SLOT_FULL** | A cleaner slot is reserved but already has a cleaner cartridge. The cleaner cartridge must be ejected first, using the [EjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmscleaner) function. |
| **ERROR_SLOT_NOT_PRESENT** | A cleaner slot is reserved but the slot specified is currently not installed in the library. This error occurs if at least one magazine is missing from the library. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

This function returns to the application as soon as the insert request is queued.

To use the
**InjectNtmsCleaner** function, the number of cleaning cycles that remain on the cleaner cartridge must be specified so that RSM can keep track of it.

If an NTMS_IEPORT object is available, the NTMS_IEPORT object directs the cartridge to the currently reserved cleaner slot.

If there is no NTMS_IEPORT object, a door access is performed. In this case, the operator is directed to place the media into the reserved slot.

## See also

[CleanNtmsDrive](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-cleanntmsdrive)

[Cleaner Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[EjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmscleaner)

[ReleaseNtmsCleanerSlot](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-releasentmscleanerslot)

[ReserveNtmsCleanerSlot](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-reserventmscleanerslot)