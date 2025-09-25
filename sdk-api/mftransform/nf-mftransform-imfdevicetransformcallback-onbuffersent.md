# IMFDeviceTransformCallback::OnBufferSent

## Description

Called when system-allocated frame buffers are sent to the device driver.

## Parameters

### `pCallbackAttributes`

The attributes containing the callback data. The System-allocated frame buffer information is stored in the attribute with the MF_DMFT_FRAME_BUFFER_INFO key.

### `pinId`

The identifier of the device pin to which the frame buffers are sent.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The frame buffer header information provided by this callback is read-only. You should not try to allocate, deallocate, open, or close anything within the header.

## See also

[IMFDeviceTransformCallback](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransformcallback)