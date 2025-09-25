## Description

Registers the indicated user callback routine to call when a port statistics event occurs.

## Parameters

### `callback`

Pointer to a callback routine to be called when the event occurs. Define your callback routine with this prototype:

`void(*)(void *pData, HBA_WWN PortWWN, HBA_UINT32 eventType)`

When your callback routine is called, the following parameters are passed to it:

* *pData*. Pointer to a buffer that contains data that you provided when registering this callback routine. You can use this data to correlate the event with the source of the event registration.
* *PortWWN*. A 64-bit world-wide name (WWN) that uniquely identifies the host bus adapter (HBA) port from which port statistics events are reported. The callback routine is called whenever an event occurs for this HBA port. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.
* *eventType*. Indicates the event type. The values assigned to this member correspond to the values associated with the [EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers) property qualifier. In particular, this member can have one of the following values: HBA_EVENT_PORT_STAT_GROWTH (a statistical counter has increased at a rate equal to or in excess of a registered rate), or HBA_EVENT_PORT_STAT_THRESHOLD (a statistical counter has reached a registered level).

### `pUserData`

Pointer to a buffer that will be passed to the callback routine with each event. This data correlates the event with the source of the event registration.

### `Handle`

Contains a value (returned by the routine [HBA_OpenAdapter](https://learn.microsoft.com/windows/win32/api/hbaapi/nf-hbaapi-hba_openadapter)) that identifies the HBA for which event callbacks are requested.

### `PortWWN`

A 64-bit world-wide name (WWN) that uniquely identifies the host bus adapter (HBA) port from which port statistics events are reported. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

### `stats`

Pointer to a structure of type [HBA_PORTSTATISTICS](https://learn.microsoft.com/windows/win32/api/hbaapi/ns-hbaapi-hba_portstatistics) that, on input, holds the statistical levels that determine when port statistics events are generated. On output, this member holds statistical data gathered for the port referenced by *PortWWN*.

### `statType`

Holds a value that indicates the mechanism used to trigger port statistics events. If the value is **HBA_EVENT_PORT_STAT_THRESHOLD**, then each non-NULL member of the [HBA_PORTSTATISTICS](https://learn.microsoft.com/windows/win32/api/hbaapi/ns-hbaapi-hba_portstatistics) structure pointed to by *stats* will indicate the threshold at which an event is generated for that particular statistical parameter. For example, if the *TxWords* member of the **HBA_PORTSTATISTICS** structure holds a value of 1,000,000, then an event will be generated once 1,000,000 words have been transmitted.

If the value of *statType* is **HBA_EVENT_PORT_STAT_GROWTH**, then the values in the [HBA_PORTSTATISTICS](https://learn.microsoft.com/windows/win32/api/hbaapi/ns-hbaapi-hba_portstatistics) structure will be interpreted as growth-rate numbers. The T11 committee's *Fibre Channel HBA API* specification recommends that port statistics be checked once a minute, and if the value or a given statistics parameter has grown by more than the number indicated for that parameter in HBA_PORTSTATISTICS, then an event is generated; but the actual frequency with which growth is monitored is hardware-specific.

### `pCallbackHandle`

Contains an opaque identifier that you can pass to [HBA_RemoveCallback](https://learn.microsoft.com/windows/win32/api/hbaapi/nf-hbaapi-hba_removecallback) to de-register the callback routine.

## Return value

A value of type [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the status of the HBA. In particular, it returns one of the following values.

|Return code|Description|
|-|-|
|HBA_STATUS_OK|The callback routine was successfully registered.|
|HBA_STATUS_ERROR_ILLEGAL_WWN|The HBA referenced by *Handle* doesn't have a port with a name that matches the value in *PortWWN*.|
|HBA_STATUS_ERROR_NOT_SUPPORTED|The hardware doesn't support statistic events.|
|HBA_STATUS_ERROR|An unspecified error occurred that prevented the registration of the callback routine.|

## Remarks

## See also