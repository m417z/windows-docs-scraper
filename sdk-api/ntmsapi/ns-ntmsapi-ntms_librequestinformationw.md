# NTMS_LIBREQUESTINFORMATIONW structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_LIBREQUESTINFORMATION** structure defines the properties specific to a work request, which are queued to RSM.

## Members

### `OperationCode`

Item operation. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_LM_CLASSIFY** | Classify the medium. |
| **NTMS_LM_CLEANDRIVE** | Clean a drive. |
| **NTMS_LM_DISABLELIBRARY** | Disable the changer. |
| **NTMS_LM_DISABLEDRIVE** | Disable a drive. |
| **NTMS_LM_DISABLEMEDIA** | Disable the medium. |
| **NTMS_LM_DISMOUNT** | Dismount the medium from a drive. |
| **NTMS_LM_DOORACCESS** | Allow access to media through a library unit door. |
| **NTMS_LM_EJECT** | Eject the medium from the library. |
| **NTMS_LM_EJECTCLEANER** | Eject a cleaner. |
| **NTMS_LM_ENABLELIBRARY** | Enable the changer. |
| **NTMS_LM_ENABLEDRIVE** | Enable a drive. |
| **NTMS_LM_ENABLEMEDIA** | Enable the medium. |
| **NTMS_LM_INJECT** | Insert the medium into the library. |
| **NTMS_LM_INJECTCLEANER** | Insert a cleaner. |
| **NTMS_LM_INVENTORY** | Perform an inventory of the library. |
| **NTMS_LM_MOUNT** | Mount a side to a drive. |
| **NTMS_LM_PROCESSOMID** | Process the OMID. |
| **NTMS_LM_RELEASECLEANER** | Release a cleaner slot. |
| **NTMS_LM_REMOVE** | Remove a work item from the queue. |
| **NTMS_LM_RESERVECLEANER** | Reserve a cleaner slot. |
| **NTMS_LM_UPDATEOMID** | Update the OMID. |
| **NTMS_LM_WRITESCRATCH** | Write a free label. |

### `OperationOption`

Work item options (command specific).

### `State`

Current state of this work item. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_LM_QUEUED** | Operation is queued. |
| **NTMS_LM_INPROCESS** | Operation is being processed. |
| **NTMS_LM_PASSED** | Operation completed successfully. |
| **NTMS_LM_FAILED** | Operation has completed with an error. |
| **NTMS_LM_WAITING** | Operation is blocked. |
| **NTMS_LM_CANCELLED** | Operation has been canceled. |
| **NTMS_LM_INVALID** | Operation is not valid. |

### `PartitionId`

Unique identifier of a side being serviced.

### `DriveId`

Unique identifier of a drive being serviced.

### `PhysMediaId`

Unique identifier of a piece of physical media being serviced.

### `Library`

Library for this request.

### `SlotId`

Unique identifier of a slot of the piece of physical media being serviced.

### `TimeQueued`

System time that this request was queued to RSM.

### `TimeCompleted`

System time that this request was completed by RSM.

### `szApplication`

Application that submitted the operator request.

### `szUser`

Interactive user logged on to the computer that submitted the operator request.

### `szComputer`

Computer that submitted the operator request.

### `dwErrorCode`

Error return for requests that return with state NTMS_LM_FAILED. This is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

### `WorkItemId`

Associated work item ID for this request. This is currently used to contain the work item ID to be canceled on an NTMS_LM_REMOVE request.

### `dwPriority`

Priority of the work item.

## Remarks

The
**NTMS_LIBREQUESTINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

GUID in the work times may become not valid over time. For example, an eject of a free medium deletes the PMID after the media is ejected. However the work item is not updated upon completion of the eject.

> [!NOTE]
> The ntmsapi.h header defines NTMS_LIBREQUESTINFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)