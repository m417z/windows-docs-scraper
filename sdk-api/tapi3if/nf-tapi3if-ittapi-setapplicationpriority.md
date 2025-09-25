# ITTAPI::SetApplicationPriority

## Description

The
**SetApplicationPriority** method allows an application to set its priority in the handoff priority list for a particular media type or Assisted Telephony request mode, or to remove itself from the priority list.

## Parameters

### `pAppFilename` [in]

Pointer to **BSTR** containing name of application.

### `lMediaType` [in]

Media associated with application.

### `fPriority` [in]

The new priority for the application. If the value VARIANT_FALSE is passed, the application is removed from the priority list for the specified media or request mode (if it was already not present, no error is generated). If the value VARIANT_TRUE is passed, the application is inserted as the highest-priority application for the media or request mode (and removed from a lower-priority position, if it was already in the list).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pAppFilename* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

The Priorities that are set with **SetApplicationPriority** will persist across reboots of the system or restarts of tapisrv. The [ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications) function opens the line with no specified call priorities. By default, the highest priority application will be the one that first called **ITTAPI::RegisterCallNotifications**.

## See also

[ITBasicCallControl::HandoffIndirect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-handoffindirect)

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)