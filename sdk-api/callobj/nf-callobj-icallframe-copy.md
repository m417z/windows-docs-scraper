# ICallFrame::Copy

## Description

Creates a copy of this call frame and all of its associated data.

**Warning** The call frame does not clean up the copied data automatically. Therefore once the copy is returned then the user is responsible for calling [Free](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-free) on the frame copy. This must be done to avoid a memory leak.

## Parameters

### `copyControl` [in]

Determines whether the copied call frame data can be shared with data in the parent frame by determining its lifetime dependency on the parent frame. For a list of values, see the [CALLFRAME_COPY](https://learn.microsoft.com/windows/win32/api/callobj/ne-callobj-callframe_copy) enumeration. If the CALLFRAME_COPY_NESTED flag is set, then the client will be responsible for using the copied call frame in a manner that its lifetime is nested in the lifetime of its parent frame making the data sharable. If the CALLFRAME_COPY_INDEPENDENT is set, then the lifetime of the copied frame will be independent of the parents.

### `pWalker` [in]

A pointer to an instance of the [ICallFrameWalker](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframewalker) interface. The [OnWalkInterface](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframewalker-onwalkinterface) method will be called for each interface pointer that is copied. If this parameter is not provided, then any interface pointer that is copied will be passed to [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref).

### `ppFrame` [out]

A pointer to an [ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe) pointer to a copy of the call frame.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Copying a frame is like unmarshalling a marshaled frame. The call frame can only be copied if it has in-parameters. If the call frame is invoked, it cannot be copied. The copy method copies interface pointers as binary values and no referenced count adjustments are performed. But if this behavior is desired, then a pointer to [ICallFrameWalker](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframewalker) can be used.

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)