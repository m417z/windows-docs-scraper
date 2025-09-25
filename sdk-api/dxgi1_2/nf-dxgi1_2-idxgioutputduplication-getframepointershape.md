# IDXGIOutputDuplication::GetFramePointerShape

## Description

Gets information about the new pointer shape for the current desktop frame.

## Parameters

### `PointerShapeBufferSize` [in]

The size in bytes of the buffer that the caller passed to the *pPointerShapeBuffer* parameter.

### `pPointerShapeBuffer` [out]

A pointer to a buffer to which **GetFramePointerShape** copies and returns pixel data for the new pointer shape.

### `pPointerShapeBufferSizeRequired` [out]

Pointer to a variable that receives the number of bytes that **GetFramePointerShape** needs to store the new pointer shape pixel data in the buffer at *pPointerShapeBuffer*.

For more information about returning the required buffer size, see Remarks.

### `pPointerShapeInfo` [out]

Pointer to a [DXGI_OUTDUPL_POINTER_SHAPE_INFO](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_pointer_shape_info) structure that receives the pointer shape information.

## Return value

**GetFramePointerShape** returns:

* S_OK if it successfully retrieved information about the new pointer shape.
* DXGI_ERROR_ACCESS_LOST if the desktop duplication interface is invalid. The desktop duplication interface typically becomes invalid when a different type of image is displayed on the desktop. Examples of this situation are:
  + Desktop switch
  + Mode change
  + Switch from DWM on, DWM off, or other full-screen applicationIn this situation, the application must release the [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface and create a new **IDXGIOutputDuplication** for the new content.
* DXGI_ERROR_MORE_DATA if the buffer that the calling application provided was not big enough.
* DXGI_ERROR_INVALID_CALL if the application called **GetFramePointerShape** without owning the desktop image.
* E_INVALIDARG if one of the parameters to **GetFramePointerShape** is incorrect; for example, if *pPointerShapeInfo* is NULL.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

**GetFramePointerShape**
stores a size value in the variable at *pPointerShapeBufferSizeRequired*. This value specifies the number of bytes that *pPointerShapeBufferSizeRequired* needs to store the new pointer shape pixel data. You can use the value in the following situations to determine the amount of memory to allocate for future buffers that you pass to *pPointerShapeBuffer*:

* **GetFramePointerShape** fails with DXGI_ERROR_MORE_DATA because the buffer is not big enough.
* **GetFramePointerShape** supplies a bigger than necessary buffer. The size value returned at *pPointerShapeBufferSizeRequired* informs the caller how much buffer space was actually used compared to how much buffer space the caller allocated and specified in the *PointerShapeBufferSize* parameter.

The *pPointerShapeInfo* parameter describes the new pointer shape.

## See also

[IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication)