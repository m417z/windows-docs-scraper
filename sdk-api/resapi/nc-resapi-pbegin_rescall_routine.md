# PBEGIN_RESCALL_ROUTINE callback function

## Description

Starts a call to a resource control code. The **PBEGIN_RESCALL_ROUTINE** type defines a pointer to this callback function.

## Parameters

### `Resource` [in]

The resource ID for the resource.

### `ControlCode` [in]

The control code to call.

### `InBuffer` [in]

A pointer to the buffer that contains the input data for the call to the control code.

### `InBufferSize` [in]

The size of the buffer specified by *InBuffer*, in bytes.

### `OutBuffer` [out]

A pointer to the buffer that contains the output data for the call to the control code.

### `OutBufferSize` [in]

The size of the buffer specified by *OutBuffer*, in bytes.

### `BytesReturned` [out]

The size of the data returned by *OutBuffer*, in bytes.

### `context` [in]

The context to the resource control code that was called.

**Windows Server 2012 R2:** This parameter was added in Windows Server 2016.

### `ReturnedAsynchronously` [out]

**TRUE** if the operation returns asynchronously; otherwise, **FALSE**.

**Windows Server 2012 R2:** This parameter was added in Windows Server 2016.

#### - resCallId [in]

This parameter was removed in Windows Server 2016.

**Windows Server 2012 R2:** This parameter is only supported in Windows Server 2012 R2.

## Return value

The function returns one of the following values, or a system error code:

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The operation completed successfully. |
| **ERROR_RESOURCE_NOT_FOUND** | The resource ID was not found. |
| **ERROR_INVALID_FUNCTION** | The requested control code is not supported. |

## See also

[Resource Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-control-codes)

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)