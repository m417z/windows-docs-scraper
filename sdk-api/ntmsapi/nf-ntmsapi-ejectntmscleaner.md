# EjectNtmsCleaner function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**EjectNtmsCleaner** function ejects the cleaning cartridge from the currently reserved cleaner slot.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpLibrary` [in]

Unique identifier of a library object.

### `lpEjectOperation` [in, out]

GUID of the eject process library operation. If *dwAction* is NTMS_EJECT_START, this parameter receives the GUID for the operation. If *dwAction* is NTMS_EJECT_STOP, this parameter must be set to the GUID for the operation to be stopped.

### `dwAction` [in]

Action to perform. This parameter can be either one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_EJECT_START** | Starts the eject operation with a port. The specified medium is ejected until the time-out event occurs or the function is called again with NTMS_EJECT_STOP. The time-out value is specified in the library object and is applied to all ejections in the library. |
| **NTMS_EJECT_STOP** | For libraries with NTMS_IEPORT objects only. Terminates the ejection process specified by *lpEjectOperation* prior to the time-out event lapsing. |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access to one or more RSM objects is denied. |
| **ERROR_INVALID_HANDLE** | The value supplied in the *hSession* parameter is not valid. |
| **ERROR_INVALID_LIBRARY** | Unable to retrieve the library definition from the database. |
| **ERROR_NO_SLOT_SET** | This library does not have a cleaner slot reserved. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_SLOT_EMPTY** | A cleaner slot is reserved but is already empty. |
| **ERROR_SLOT_NOT_PRESENT** | A cleaner slot is reserved but the slot is currently not installed in the library. This error occurs when at least one magazine is missing from the library. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The
**EjectNtmsCleaner** function returns to the application as soon as the eject request is queued.

If the library specified in the
**EjectNtmsCleaner** function has an NTMS_IEPORT object, RSM uses the NTMS_IEPORT object to eject the cleaner. If there is no NTMS_IEPORT object, the NTMS_IEDOOR object is used to allow the operator to gain access to the cleaner slot.

Ejected cleaner cartridges are not tracked in the offline library.

## See also

[CleanNtmsDrive](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-cleanntmsdrive)

[Cleaner Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[InjectNtmsCleaner](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-injectntmscleaner)

[ReleaseNtmsCleanerSlot](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-releasentmscleanerslot)

[ReserveNtmsCleanerSlot](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-reserventmscleanerslot)