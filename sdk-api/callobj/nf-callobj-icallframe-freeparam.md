# ICallFrame::FreeParam

## Description

Frees the specified parameter in the frame.

## Parameters

### `iparam` [in]

The number of the parameter to be freed.

### `freeFlags` [in]

Represents flags from the [CALLFRAME_FREE](https://learn.microsoft.com/windows/desktop/api/callobj/ne-callobj-callframe_free) enumeration.

### `pWalkerFree` [in]

A pointer to an instance of the [ICallFrameWalker](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframewalker) interface. When specified, a callback is made for each interface pointer encountered while freeing occurs. If this parameter is not specified, then the interface pointers are freed by the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

### `nullFlags` [in]

Represents flags from the [CALLFRAME_NULL](https://learn.microsoft.com/windows/desktop/api/callobj/ne-callobj-callframe_null) enumeration.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)