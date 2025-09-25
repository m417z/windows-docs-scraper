# ICallFrame::Free

## Description

Frees the frame copy to avoid a memory leak.

When a copy of a call frame is made with the [Copy](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-copy) method, the call frame does not clean up the copied data automatically. Therefore, after a copy of the call frame is returned, the user is responsible for calling the **Free** method to free the frame copy and avoid a memory leak.

## Parameters

### `pframeArgsDest` [in]

A pointer to an instance of the [ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe) interface. Represents the stack pointer of the call frame to which the out parameters should be copied before the frame copy is freed. The destination frame is usually the parent frame from which the frame was originally copied. This parameter is optional.

When freeing a frame and specifying a *pframeArgsDest* parameter which is in the same memory space as that of the receiver frame, then only the *pWalkerCopy* parameter is called on each interface pointer.

### `pWalkerDestFree` [in]

A pointer to an instance of the [ICallFrameWalker](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframewalker) interface. If there exist in and out parameters in *pframeArgsDest*, then the propagation requires that those values be freed. By providing the *pWalkerDestFree* object, interface pointers will be freed. If *pframeArgsDest* is **NULL**, then this parameter must also be **NULL** and the interface pointers should be released by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

### `pWalkerCopy` [in]

A pointer to an instance of the [ICallFrameWalker](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframewalker) interface. When the in and out parameters in *pframeArgsDest* are freed, then the propagation of out parameters is carried out. If this parameter is not specified, then the interface pointers will be passed to [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref). This parameter is optional.

### `freeFlags` [in]

Flags from the [CALLFRAME_FREE](https://learn.microsoft.com/windows/desktop/api/callobj/ne-callobj-callframe_free) enumeration.

### `pWalkerFree` [in]

A pointer to an instance of the [ICallFrameWalker](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframewalker) interface. When specified, a callback is made for each interface pointer encountered while freeing occurs. If this parameter is not specified, then the interface pointers are freed by the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

### `nullFlags` [in]

Flags from the [CALLFRAME_NULL](https://learn.microsoft.com/windows/desktop/api/callobj/ne-callobj-callframe_null) enumeration.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)