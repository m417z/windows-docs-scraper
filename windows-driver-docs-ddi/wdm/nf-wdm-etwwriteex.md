# EtwWriteEx function

## Description

The **EtwWriteEx** function is a tracing function for publishing events that support filtering in your kernel-mode driver code.

## Parameters

### `RegHandle` [in]

A pointer to the event provider registration handle, which is returned by the [EtwRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwregister) function if the event provider registration is successful.

### `EventDescriptor` [in]

A pointer to the [EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_descriptor) structure.

### `Filter` [in]

The instance identifiers that identify the session to which the event will not written. That is, the value is a mask of sessions which should be excluded from logging (filtered out). Use a bitwise OR to specify multiple identifiers. Set to zero if you do not support filters or if the event is being written to all sessions (no filters failed). For information on getting the identifier for a session, see the *FilterData* parameter of your [EtwEnableCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-etwenablecallback) callback.

### `Flags` [in]

Reserved. Must be zero (0).

### `ActivityId` [in, optional]

The identifier that indicates the activity associated with the event. The *ActivityID* provides a way to group related events and is used in end-to-end tracing. If NULL, ETW gets the identifier from the thread local storage. For details on getting this identifier, see [EtwActivityIdControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwactivityidcontrol).

### `RelatedActivityId` [in, optional]

Activity identifier from the previous component. Use this parameter to link your component's events to the previous component's events. To get the activity identifier that was set for the previous component, see the descriptions for the *ControlCode* parameter of the [EtwActivityIdControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwactivityidcontrol) function.

### `UserDataCount` [in]

Number of EVENT_DATA_DESCRIPTOR structures in *UserData*. The maximum number is 128.

### `UserData` [in, optional]

A pointer to the array of EVENT_DATA_DESCRIPTOR structures. Set this parameter to NULL if *UserDataCount* is zero. The data must be in the order specified in the manifest.

## Return value

Returns ERROR_SUCCESS if successful or one of the following values on error.

## Remarks

The **EtwWriteEx** function is the kernel-mode equivalent of the user-mode [EventWriteEx](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventwriteex) function. Event data written with this function requires a manifest. The manifest is embedded in the provider, so the provider must be available for a consumer to consume the data. To ensure that there is a consumer for the event you are publishing, you can precede the call to **EtwWrite** with a call to [EtwEventEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etweventenabled) or [EtwProviderEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwproviderenabled).

Use the *ActivityId* and *RelatedActivityId* parameters when you want to relate events in different components in an end-to-end tracing scenario. For example, components A, B, and C perform work on a related activity and want to link their events so that a consumer can consume all the events related to that activity.

You can call **EtwWriteEx** at any IRQL. However, when IRQL is greater than APC_LEVEL, any data passed to the **EtwWrite**, **EtwWriteEx**, **EtwWriteString**, **EtwWriteTransfer** functions must not be pageable. That is, any kernel-mode routine that is running at IRQL greater than APC_LEVEL cannot access pageable memory. Data passed to the **EtwWrite**, **EtwWriteEx**, **EtwWriteString**, and **EtwWriteTransfer** functions must reside in system-space memory, regardless of what the IRQL is.

## See also

[EtwWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwwrite)

[EventWrite](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventwrite)

[EventWriteEx](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventwriteex)