## Description

The **EtwActivityIdControl** function creates, queries, and sets the current activity identifier.

## Parameters

### `ControlCode` [in]

The *ControlCode* parameter can be one of the following defined values.

| Value | Meaning |
|---|---|
| **EVENT_ACTIVITY_CTRL_GET_ID** | Returns the current thread's activity identifier in the *ActivityId* parameter. |
| **EVENT_ACTIVITY_CTRL_SET_ID** | Sets the current thread's activity identifier to the value specified in *ActivityId*. Note that the *ActivityId* you pass to this function does not necessarily have to be one created by **EVENT_ACTIVITY_CTRL_CREATE_ID** or **EVENT_ACTIVITY_CTRL_CREATE_SET_ID** control code. You can use any value that fits inside a GUID, including any available local value that would serve your need for some type of activity identifier. |
| **EVENT_ACTIVITY_CTRL_CREATE_ID** | Creates a new identifier and sets the *ActivityId* parameter to the value of the new identifier. |
| **EVENT_ACTIVITY_CTRL_GET_SET_ID** | Sets the current thread's activity identifier to the value specified in *ActivityId*, and then returns *ActivityId* with the value of the thread's activity identifier prior to the function call. |
| **EVENT_ACTIVITY_CTRL_CREATE_SET_ID** | Copies the current thread's activity identifier. Creates a new identifier and sets the current thread's activity identifier to the new value. Returns *ActivityId* with the value of the thread's activity identifier prior to the function call. |

### `ActivityId` [in, out]

The identifier that indicates the activity associated with the event. The *ActivityId* parameter provides a way to group related events and is used in end-to-end tracing.

## Return value

**EtwActivityIdControl** returns STATUS_SUCCESS or an appropriate NTSTATUS value.

## Remarks

Activity identifiers provide a method of linking separate events in a common thread of computation. An *activity* is a work item performed by an application and or a driver. The concept of activity is a core component in end-to-end tracing.

Callers of **EtwActivityIdControl** must be running at IRQL < DISPATCH_LEVEL, unless the *ControlCode* is **EVENT_ACTIVITY_CTRL_CREATE_ID**, in which case the function can be called at any IRQL.

Use the [EtwActivityIdControlKernel](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn268326(v=vs.85)) function to query or set activity identifiers kernel threads.

## See also

[EtwActivityIdControlKernel](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/dn268326(v=vs.85))