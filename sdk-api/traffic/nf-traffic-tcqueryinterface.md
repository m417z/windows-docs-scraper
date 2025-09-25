# TcQueryInterface function

## Description

The
**TcQueryInterface** function queries traffic control for related per-interface parameters. A traffic control parameter is queried by providing its globally unique identifier (GUID). Setting the *NotifyChange* parameter to **TRUE** enables event notification on the specified GUID, after which notification events are sent to a client whenever the queried parameter changes. GUIDs for which clients can request notification are found in the
[GUID](https://learn.microsoft.com/previous-versions/windows/desktop/qos/guid) entry; the column titled "Notification" denotes which GUIDs are available for notification.

## Parameters

### `IfcHandle` [in]

Handle associated with the interface to be queried. This handle is obtained by a previous call to the
[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea) function.

### `pGuidParam` [in]

Pointer to the globally unique identifier (GUID) that corresponds to the traffic control parameter being queried.

### `NotifyChange` [in]

Used to request notifications from traffic control for the parameter being queried. If **TRUE**, traffic control will notify the client, through the
[ClNotifyHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_notify_handler) function, upon changes to the parameter corresponding to the GUID provided in *pGuidParam*. Notifications are off by default.

### `pBufferSize` [in, out]

Indicates the size of the buffer, in bytes. For input, this value is the size of the buffer allocated by the caller. For output, this value is the actual size of the buffer, in bytes, used by traffic control.

### `Buffer` [out]

Pointer to a client-allocated buffer into which returned data will be written.

## Return value

Note that, with regard to a requested notification state, only a return value of NO_ERROR will result in the application of the requested notification state. If a return value other than NO_ERROR is returned from a call to the
**TcQueryInterface** function, the requested change in notification state will not be accepted.

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_HANDLE** | Invalid interface handle. |
| **ERROR_INVALID_PARAMETER** | Invalid or **NULL** parameter. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is too small to store the results. |
| **ERROR_NOT_SUPPORTED** | Querying for the GUID provided is not supported on the provided interface. |
| **ERROR_WMI_GUID_NOT_FOUND** | The device did not register for this GUID. |
| **ERROR_WMI_INSTANCE_NOT_FOUND** | The instance name was not found, likely because the interface is in the process of being closed. |

## Remarks

**Note** Use of the
**TcQueryInterface** function requires administrative privilege.

## See also

[ClNotifyHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_notify_handler)

[TcEnumerateInterfaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateinterfaces)

[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient)