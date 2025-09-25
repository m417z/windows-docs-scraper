# PEND_CONTROL_CALL callback function

## Description

Called when a resource control code operation completes. The **PEND_CONTROL_CALL** type defines a pointer to this function.

## Parameters

### `context`

### `status` [in]

The context of the call to the resource control code.

**Windows Server 2012 R2:** Not supported.

The status of the operation.

#### - resCallId [in]

Not supported.

**Windows Server 2012 R2:** TBD

## Return value

**ERROR_SUCCESS** if the operation is successful; otherwise, a system error code.

## See also

[Resource DLL Callback Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-callback-functions)