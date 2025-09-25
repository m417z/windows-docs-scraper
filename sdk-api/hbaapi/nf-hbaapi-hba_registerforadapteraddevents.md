## Description

Registers the indicated user callback routine to call when a new adapter is added to the system.

## Parameters

### `callback`

Pointer to a callback routine to be called when an adapter is added to the system. Define your callback routine with this prototype:

`void(*)(void *pData, HBA_WWN PortWWN, HBA_UINT32 eventType)`

When your callback routine is called, the following parameters are passed to it:

* *pData*. Pointer to a buffer that contains data that you provided when registering this callback routine. You can use this data to correlate the event with the source of the event registration.
* *PortWWN*. A 64-bit world-wide name (WWN) that uniquely identifies the host bus adapter (HBA) from which the adapter event is being reported. The callback routine is called whenever an adapter event occurs for this HBA. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.
* *eventType*. Indicates the event type. The values assigned to this member correspond to the values associated with the [EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers) property qualifier.

### `pUserData`

Pointer to a buffer that will be passed to the callback routine with each event. This data correlates the event with the source of the event registration.

### `pCallbackHandle`

Contains an opaque identifier that you can pass to [HBA_RemoveCallback](https://learn.microsoft.com/windows/win32/api/hbaapi/nf-hbaapi-hba_removecallback) to de-register the callback routine.

## Return value

A value of type [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the status of the HBA. In particular, it returns one of the following values.

|Return code|Description|
|-|-|
|HBA_STATUS_OK|The callback routine was successfully registered.|
|HBA_STATUS_ERROR|An unspecified error occurred that prevented the registration of the callback routine.|

## Remarks

When a new adapter is added to the system, an event of type **HBA_EVENT_ADAPTER_ADD** is generated.

## See also