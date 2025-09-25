## Description

Retrieves the multi-group processor mask of the specified node.

## Parameters

### `NodeNumber`

Supplies the zero-based node number for the node of interest.

### `ProcessorMasks`

An array of [GROUP_AFFINITY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-group_affinity) structures, which upon successful return describes the processor mask of the specified node.

Each element in the array describes a set of processors that belong to the node within a single processor group. There will be one element in the resulting array for each processor group this node has active processors in.

### `ProcessorMaskCount`

Specifies the size of the *ProcessorMasks* array, in elements.

### `RequiredMaskCount`

On successful return, specifies the number of affinity structures written to the array.

If the input array was too small, the function fails with **ERROR_INSUFFICIENT_BUFFER** and sets the *RequiredMaskCount* parameter to the number of elements required.

The number of required elements is always less than or equal to the maximum group count returned by [GetMaximumProcessorGroupCount](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getmaximumprocessorgroupcount).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero and extended error information can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the array supplied is too small, the error value is **ERROR_INSUFFICIENT_BUFFER** and the RequiredMaskCount parameter is set to the number of elements required.

If the *NodeNumber* supplied is invalid (i.e. greater than the value returned by GetNumaHighestNodeNumber), the error value is **ERROR_INVALID_PARAMETER**.

## Remarks

If the node specified does not have any processors associated with it (i.e. it only contains memory or peripherals), then the *RequiredMaskCount* returned will be 0 and no structures will be written to the array.

## See also

[GetMaximumProcessorGroupCount](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getmaximumprocessorgroupcount)