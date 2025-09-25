# IDXGIOutputDuplication::GetFrameMoveRects

## Description

Gets information about the moved rectangles for the current desktop frame.

## Parameters

### `MoveRectsBufferSize` [in]

The size in bytes of the buffer that the caller passed to the *pMoveRectBuffer* parameter.

### `pMoveRectBuffer` [out]

A pointer to an array of
[DXGI_OUTDUPL_MOVE_RECT](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_move_rect) structures
that identifies the moved rectangle regions for the desktop frame.

### `pMoveRectsBufferSizeRequired` [out]

Pointer to a variable that receives the number of bytes that
**GetFrameMoveRects**
needs to store information about moved regions in the buffer at *pMoveRectBuffer*.

For more information about returning the required buffer size, see Remarks.

## Return value

**GetFrameMoveRects**
returns:

* S_OK if it successfully retrieved information about moved rectangles.
* DXGI_ERROR_ACCESS_LOST if the desktop duplication interface is invalid. The desktop duplication interface typically becomes invalid when a different type of image is displayed on the desktop. Examples of this situation are:
  + Desktop switch
  + Mode change
  + Switch from DWM on, DWM off, or other full-screen applicationIn this situation, the application must release the
  [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface and
  create a new **IDXGIOutputDuplication**
  for the new content.
* DXGI_ERROR_MORE_DATA if the buffer that the calling application provided
  is not big enough.
* DXGI_ERROR_INVALID_CALL if the application called
  **GetFrameMoveRects**
  without owning the desktop image.
* E_INVALIDARG if one of the parameters to
  **GetFrameMoveRects**
  is incorrect; for example, if
  *pMoveRectBuffer* is NULL.
* Possibly other error codes that are described in the
  [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

**GetFrameMoveRects**
stores a size value in the variable at *pMoveRectsBufferSizeRequired*. This value specifies the number of bytes that **GetFrameMoveRects** needs to store information about moved regions. You can use
this value in the following situations to determine the amount of memory to allocate for future buffers that you pass to *pMoveRectBuffer*:

* **GetFrameMoveRects** fails with DXGI_ERROR_MORE_DATA because the buffer is not big enough.
* **GetFrameMoveRects** supplies a buffer that is bigger than necessary. The size value returned at *pMoveRectsBufferSizeRequired* informs the caller how much buffer space was actually used compared to how much buffer space the caller allocated and specified in the *MoveRectsBufferSize* parameter.

The caller can also use the value returned at *pMoveRectsBufferSizeRequired* to determine the number of [DXGI_OUTDUPL_MOVE_RECT](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_move_rect) structures returned.

The buffer contains the list of move RECTs for the current frame.

**Note** To produce a visually accurate copy of the desktop, an application must first process all move RECTs before it processes dirty RECTs.

## See also

[IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication)