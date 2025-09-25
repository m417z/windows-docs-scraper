# IDXGIOutputDuplication::GetFrameDirtyRects

## Description

Gets information about dirty rectangles for the current desktop frame.

## Parameters

### `DirtyRectsBufferSize` [in]

The size in bytes of the buffer that the caller passed to the *pDirtyRectsBuffer*
parameter.

### `pDirtyRectsBuffer` [out]

A pointer to an array of [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures
that identifies the dirty rectangle regions for the desktop frame.

### `pDirtyRectsBufferSizeRequired` [out]

Pointer to a variable that receives the number of bytes that
**GetFrameDirtyRects**
needs to store information about dirty regions in the buffer at
*pDirtyRectsBuffer*.

For more information about returning the required buffer size, see Remarks.

## Return value

**GetFrameDirtyRects**
returns:

* S_OK if it successfully retrieved information about dirty rectangles.
* DXGI_ERROR_ACCESS_LOST if the desktop duplication interface is invalid. The desktop duplication
  interface typically becomes invalid when a different type of image is displayed on the desktop. Examples of
  this situation are:
  + Desktop switch
  + Mode change
  + Switch from DWM on, DWM off, or other full-screen applicationIn this situation, the application must release the
  [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface and
  create a new
  **IDXGIOutputDuplication** for the new
  content.
* DXGI_ERROR_MORE_DATA if the buffer that the calling application provided was not big enough.
* DXGI_ERROR_INVALID_CALL if the application called
  **GetFrameDirtyRects**
  without owning the desktop image.
* E_INVALIDARG if one of the parameters to
  **GetFrameDirtyRects**
  is incorrect; for example, if *pDirtyRectsBuffer* is NULL.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

**GetFrameDirtyRects** stores a size value in the variable at *pDirtyRectsBufferSizeRequired*. This value specifies the number of bytes that **GetFrameDirtyRects** needs to store information about dirty regions. You can use this value
in the following situations to determine the amount of memory to allocate for future buffers that you pass to *pDirtyRectsBuffer*:

* **GetFrameDirtyRects**
  fails with DXGI_ERROR_MORE_DATA because the buffer is not big enough.
* **GetFrameDirtyRects**
  supplies a buffer that is bigger than necessary. The size value returned at
  *pDirtyRectsBufferSizeRequired* informs the caller how much buffer space was actually
  used compared to how much buffer space the caller allocated and specified in the
  *DirtyRectsBufferSize* parameter.

The caller can also use the value returned at *pDirtyRectsBufferSizeRequired* to
determine the number of [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)s returned in the *pDirtyRectsBuffer* array.

The buffer contains the list of dirty [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)s for the current frame.

**Note** To produce a visually accurate copy of the desktop, an application must first process all move [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)s before
it processes dirty **RECT**s.

## See also

[IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication)