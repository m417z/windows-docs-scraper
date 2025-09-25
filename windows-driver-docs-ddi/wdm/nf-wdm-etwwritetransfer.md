## Description

The **EtwWriteTransfer** function marks an event that links two activities together; this type of event is referred to as a *transfer event*. A transfer event can contain the same user-defined data, the same fields, and is subject to the same rules as other events.

## Parameters

### `RegHandle` [in]

A pointer to the event provider registration handle, which is returned by the **EtwRegister** function if the event provider registration is successful.

### `EventDescriptor` [in]

A pointer to the EVENT_DESCRIPTOR structure.

### `ActivityId` [in, optional]

The identifier that indicates the activity associated with the event. The *ActivityId* provides a way to group related events and is used in end-to-end tracing. This identifier is optional and can be **NULL**.

### `RelatedActivityId` [in, optional]

The identifier that indicates related activity associated with the event. The *RelatedActivityID* provides a way to group related events and is used in end-to-end tracing.

### `UserDataCount` [in]

The number of elements in an array of EVENT_DATA_DESCRIPTOR structures.

### `UserData` [in, optional]

The pointer to the first element in an array of EVENT_DATA_DESCRIPTOR structures.

## Return value

**EtwWriteTransfer** returns STATUS_SUCCESS if the event was successfully published.

## Remarks

You can call **EtwWriteTransfer** at any IRQL. However, when IRQL is greater than APC_LEVEL, any data passed to the **EtwWrite**, **EtwWriteString**, **EtwWriteTransfer** functions must not be pageable. That is, any kernel-mode routine that is running at IRQL greater than APC_LEVEL cannot access pageable memory. Data passed to the **EtwWrite**, **EtwWriteString**, **EtwWriteTransfer** functions must reside in system-space memory, regardless of what the IRQL is.

## See also

[EtwWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwwrite)

[EtwWriteString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwwritestring)