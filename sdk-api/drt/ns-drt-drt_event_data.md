## Description

The **DRT_EVENT_DATA** structure contains the event data returned by calling [DrtGetEventData](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgeteventdata) after an application receives an event signal on the *hEvent* passed into [DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen).

Contains an unnamed union that contains a structure that defines a change in the leaf set, the state of a locally registered key, or the state of the local DRT instance.

## Members

### `type`

A [DRT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_event_type) enumeration that specifies the event type.

### `hr`

The HRESULT of the operation for which the event was signaled that indicates if a result is the last result within a search.

### `pvContext`

Pointer to the context data passed to the API that generated the event. For example, if data is passed into the *pvContext* parameter of [DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen), that data is returned through this field.

### `leafsetKeyChange`

This structure appears when the event has been raised to signal a change in a leaf set of a locally registered key; the **type** field of the **DRT_EVENT_DATA** structure is set to DRT_EVENT_LEAFSET_KEY_CHANGED.

### `leafsetKeyChange.change`

Specifies the type of key change that has occurred.

### `leafsetKeyChange.localKey`

Specifies the local key associated with the leaf set that has changed.

### `leafsetKeyChange.remoteKey`

Specifies the remote key that changed.

### `registrationStateChange`

This structure appears when the event has been raised to signal a change in a local key registration; the **type** field of the **DRT_EVENT_DATA** structure is set to DRT_EVENT_REGISTRATION_STATE_CHANGED.

### `registrationStateChange.state`

Specifies the type of registration state change that has occurred.

### `registrationStateChange.localKey`

Specifies the local key associated with the registration that has changed.

### `statusChange`

This structure appears when the event has been raised to signal a state change in the local DRT instance; the **type** field of the **DRT_EVENT_DATA** structure is set to DRT_EVENT_STATUS_CHANGED.

### `statusChange.status`

Contains the current [DRT_STATUS](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_status) of the local DRT instance.

### `statusChange.bootstrapAddresses`

This structure contains the addresses returned by the bootstrap provider when the DRT attempts to join the mesh. This structure is completed only when the DRT transitions to the DRT_ALONE state. The contents of this structure can be used to diagnose connectivity issues between the local DRT instance and other nodes already present in the mesh.

### `statusChange.bootstrapAddresses.cntAddress`

Contains the number of addresses in **pAddresses**.

### `statusChange.bootstrapAddresses.pAddresses`

Contains an array of addresses returned by the bootstrap provider.
## See also

[DRT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_event_type)

[DRT_STATUS](https://learn.microsoft.com/windows/desktop/api/drt/ne-drt-drt_status)

[DrtGetEventData](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgeteventdata)

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)