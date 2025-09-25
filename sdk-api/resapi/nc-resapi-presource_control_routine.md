# PRESOURCE_CONTROL_ROUTINE callback function

## Description

Performs an operation that applies to a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The
**PRESOURCE_CONTROL_ROUTINE** type defines a pointer to this function.

## Parameters

### `Resource` [in]

Resource identifier of the affected resource.

### `ControlCode` [in]

[Control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/about-control-codes) that represents the operation to be
performed. For a list of valid values for the *ControlCode* parameter, see
[Resource Type Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-type-control-codes).

### `InBuffer` [in, optional]

Pointer to a buffer containing data to be used in the operation. *InBuffer* can be
**NULL** if no data is required.

### `InBufferSize` [in]

Size, in bytes, of the buffer pointed to by *InBuffer*.

### `OutBuffer` [out, optional]

Pointer to a buffer containing data resulting from the operation. *OutBuffer* can be
**NULL** if the operation does not need to return data.

### `OutBufferSize` [in]

Size, in bytes, of the available space pointed to by *OutBuffer*.

### `BytesReturned` [out]

Actual size, in bytes, of the data resulting from the operation.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation associated with *ControlCode* was completed successfully. |
| **ERROR_INVALID_FUNCTION**<br><br>1 | The [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) requested that the [Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor) perform default processing (if any) for *ControlCode* in addition to processing supplied by the DLL (if any). |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The allocated size of *OutBuffer* was too small to hold the requested data. *BytesReturned* indicates the required size. Always include the terminating **NULL** when calculating the byte sizes of strings. |
| **ERROR_RESOURCE_PROPERTIES_STORED**<br><br>5024 (0x13A0) | Indicates that new property values for a resource have been set in the cluster database, but the properties have not yet taken effect. The new property values will be applied after the resource is taken offline and brought online. |
| **[Error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation was unsuccessful. |

## Remarks

Some control codes should be handled by the resource DLL, while others should be left to the Resource Monitor.
For effective implementation strategies of the
*ResourceControl* entry-point function, see
[Implementing ResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-resourcecontrol).

#### Examples

See [Resource DLL Examples](https://learn.microsoft.com/previous-versions/aa372246(v=vs.85)).

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)