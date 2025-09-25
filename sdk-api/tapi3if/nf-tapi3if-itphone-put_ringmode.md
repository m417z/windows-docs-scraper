# ITPhone::put_RingMode

## Description

The
**put_RingMode** method requests that the phone change its ring mode.

The application must call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before invoking this method; otherwise, the invocation fails.

## Parameters

### `lRingMode` [in]

Ring mode.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[get_RingMode](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_ringmode)