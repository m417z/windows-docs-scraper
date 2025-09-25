# ITPhone::put_RingVolume

## Description

The
**put_RingVolume** method requests that the phone change its ring volume.

The application must call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before invoking this method; otherwise, the invocation fails.

## Parameters

### `lRingVolume` [in]

Phone volume. For more information, see the following Remarks section.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the phone is currently ringing (RingMode != 0), the new volume takes effect immediately. If the phone is not currently ringing (RingMode == 0), the new volume takes effect the next time the phone rings.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[get_RingVolume](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_ringvolume)