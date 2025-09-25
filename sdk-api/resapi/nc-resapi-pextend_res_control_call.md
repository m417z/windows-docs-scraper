# PEXTEND_RES_CONTROL_CALL callback function

## Description

Extends the timeout for a call to a resource control code. The **PEXTEND_RES_CONTROL_CALL** type defines a pointer to this function.

## Parameters

### `context` [in]

The context to the resource control code that was called.

### `newTimeoutInMs` [in]

The new timeout, in milliseconds.

## Return value

**ERROR_SUCCESS** if the operation is successful; otherwise, a system error code.

## See also

[Resource Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-control-codes)

[Resource DLL Callback Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-callback-functions)