## Description

Registers the indicated user callback routine to call when a port event occurs.

## Parameters

### `callback`

Pointer to a callback routine to be called when the event occurs. Define your callback routine with this prototype:

`void(*)(void *pData, HBA_WWN PortWWN, HBA_UINT32 eventType, HBA_UINT32 fabricPortID)`

When your callback routine is called, the following parameters are passed to it:

* *pData*. Pointer to a buffer that contains data that you provided when registering this callback routine. You can use this data to correlate the event with the source of the event registration.
* *PortWWN*. A 64-bit world-wide name (WWN) that uniquely identifies the host bus adapter (HBA) port from which port events are reported. The callback routine is called whenever an event occurs for this port. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.
* *eventType*. Indicates the event type. The values assigned to this member correspond to the values associated with the [EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers) property qualifier. In particular, this member can have one of the following values: HBA_EVENT_PORT_FABRIC (a local port has received a registered state change notification, or RSCN, command. When this event occurs, *fabricPortID* contains the port identifier page for the sub-section of the fabric that has changed, as explained in the T11 committee's *Fibre Channel Framing and Signaling*, or FC-FS, specification), or HBA_EVENT_PORT_OFFLINE (a local port has gone offline), or HBA_EVENT_PORT_NEW_TARGETS (a local port has added target devices to its discovered remote ports), or HBA_EVENT_PORT_ONLINE (a local port has come online), or HBA_EVENT_PORT_UNKNOWN (the port event is unknown).
* *fabricPortID*. Pointer to a buffer that contains the port ID page for the sub-section of the fabric that has changed, as explained in the T11 committee's *Fibre Channel Framing and Signaling (FC-FS)* specification.

### `UserData`

Pointer to a buffer that will be passed to the callback routine with each event. This data correlates the event with the source of the event registration.

### `Handle`

Contains a value (returned by the routine [HBA_OpenAdapter](https://learn.microsoft.com/windows/win32/api/hbaapi/nf-hbaapi-hba_openadapter)) that identifies the HBA for which event callbacks are requested.

### `PortWWN`

A 64-bit world-wide name (WWN) that uniquely identifies the host bus adapter (HBA) port from which port events are reported. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

### `pCallbackHandle`

Contains an opaque identifier that you can pass to [HBA_RemoveCallback](https://learn.microsoft.com/windows/win32/api/hbaapi/nf-hbaapi-hba_removecallback) to de-register the callback routine.

## Return value

A value of type [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the status of the HBA. In particular, it returns one of the following values.

|Return code|Description|
|-|-|
|HBA_STATUS_OK|The callback routine was successfully registered.|
|HBA_STATUS_ERROR_ILLEGAL_WWN|Returned if the HBA referenced by *handle* doesn't have a port with a name that matches the value in *PortWWN*.|
|HBA_STATUS_ERROR|An unspecified error occurred that prevented the registration of the callback routine.|

## Remarks

For a list of port events, see *eventType* in the *callback* parameter.

## See also