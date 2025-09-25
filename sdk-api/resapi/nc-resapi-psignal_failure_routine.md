# PSIGNAL_FAILURE_ROUTINE callback function

## Description

Reports that there was a failure in a resource instance. The **PSIGNAL_FAILURE_ROUTINE** type defines a pointer to this function.

## Parameters

### `ResourceHandle` [in]

A handle to the resource instance.

### `FailureType` [in]

A [FAILURE_TYPE](https://learn.microsoft.com/windows/desktop/api/resapi/ne-resapi-failure_type) enumeration value that describes the failure type.

**Windows Server 2012:** Not supported.

### `ApplicationSpecificErrorCode` [in]

An application error code.

#### - IsEmbeddedFailure [in]

Not supported.

**Windows Server 2012:** **TRUE** if this failure is an embedded failure; otherwise **FALSE**.

## Return value

Returns **ERROR_SUCCESS** (0), if the operation succeeds; otherwise returns a system error code.

## See also

[Resource DLL Callback Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-callback-functions)