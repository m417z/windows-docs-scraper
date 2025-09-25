# PRESOURCE_TYPE_CONTROL_ROUTINE callback function

## Description

Performs an operation that applies to a
[resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types). The
**PRESOURCE_TYPE_CONTROL_ROUTINE** type defines a pointer to this function.

## Parameters

### `ResourceTypeName` [in]

Type of resource to be affected by the operation.

### `ControlCode` [in]

[Control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/about-control-codes) that represents the operation to be
performed. For a list of valid values for the *ControlCode* parameter, see
[Resource Type Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-type-control-codes).

### `InBuffer` [in]

Pointer to a buffer containing data to be used in the operation. *InBuffer* can be
**NULL** if the operation does not require data.

### `InBufferSize` [in]

Size, in bytes, of the buffer pointed to by *InBuffer*.

### `OutBuffer` [out]

Pointer to a buffer containing data resulting from the operation. *OutBuffer* can be
**NULL** if the operation returns no data.

### `OutBufferSize` [in]

Size, in bytes, of the available space pointed to by *OutBuffer*.

### `BytesReturned` [out]

Number of bytes in the buffer pointed to by *OutBuffer* that actually contain
data.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error
code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FUNCTION** | The resource DLL requested that the [Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor) perform default processing (if any) for *ControlCode* in addition to processing supplied by the DLL (if any). |

## Remarks

Some control codes should be handled by the [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls),
while others should be left to the Resource Monitor. For effective implementation strategies of the
**ResourceTypeControl** entry-point function, see
[Implementing ResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-resourcetypecontrol).

#### Examples

See [Resource DLL Examples](https://learn.microsoft.com/previous-versions/aa372246(v=vs.85)).

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)