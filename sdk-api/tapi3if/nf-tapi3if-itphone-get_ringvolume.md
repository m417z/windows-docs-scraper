# ITPhone::get_RingVolume

## Description

The
**get_RingVolume** method retrieves the current ring volume for the phone.

The application must call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before invoking this method; otherwise, the invocation fails.

## Parameters

### `plRingVolume` [out]

Ring volume.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[put_RingVolume](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-put_ringvolume)