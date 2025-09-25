# IDXGIOutputDuplication::AcquireNextFrame

## Description

Indicates that the application is ready to process the next desktop image.

## Parameters

### `TimeoutInMilliseconds` [in]

The time-out interval, in milliseconds. This interval specifies the amount of time that this method waits for a new frame before it returns to the caller. This method returns if the interval elapses, and a new desktop image is not available.

For more information about the time-out interval, see Remarks.

### `pFrameInfo` [out]

A pointer to a memory location that receives the [DXGI_OUTDUPL_FRAME_INFO](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_frame_info) structure that describes timing and presentation statistics for a frame.

### `ppDesktopResource` [out]

A pointer to a variable that receives the [IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource) interface of the surface that contains the desktop bitmap.

## Return value

**AcquireNextFrame** returns:

* S_OK if it successfully received the next desktop image.
* DXGI_ERROR_ACCESS_LOST if the desktop duplication interface is invalid. The desktop duplication interface typically becomes invalid when a different type of image is displayed on the desktop. Examples of this situation are:
  + Desktop switch
  + Mode change
  + Switch from DWM on, DWM off, or other full-screen applicationIn this situation, the application must release the [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface and create a new **IDXGIOutputDuplication** for the new content.
* DXGI_ERROR_WAIT_TIMEOUT if the time-out interval elapsed before the next desktop frame was available.
* DXGI_ERROR_INVALID_CALL if the application called **AcquireNextFrame** without releasing the previous frame.
* E_INVALIDARG if one of the parameters to **AcquireNextFrame** is incorrect; for example, if *pFrameInfo* is NULL.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

When **AcquireNextFrame** returns successfully, the calling application can access the desktop image that **AcquireNextFrame** returns in the variable at *ppDesktopResource*.
If the caller specifies a zero time-out interval in the *TimeoutInMilliseconds* parameter, **AcquireNextFrame** verifies whether there is a new desktop image available, returns immediately, and indicates its outcome with the return value. If the caller specifies an **INFINITE** time-out interval in the *TimeoutInMilliseconds* parameter, the time-out interval never elapses.

**Note** You cannot cancel the wait that you specified in the *TimeoutInMilliseconds* parameter. Therefore, if you must periodically check for other conditions (for example, a terminate signal), you should specify a non-**INFINITE** time-out interval. After the time-out interval elapses, you can check for these other conditions and then call **AcquireNextFrame** again to wait for the next frame.

**AcquireNextFrame** acquires a new desktop frame when the operating system either updates the desktop bitmap image or changes the shape or position of a hardware pointer. The new frame that **AcquireNextFrame** acquires might have only the desktop image updated, only the pointer shape or position updated, or both.

## See also

[IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication)