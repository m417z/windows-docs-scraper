# ITPhone::get_RingMode

## Description

The
**get_RingMode** method retrieves the current ring mode for the phone.

The application must call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before invoking this method; otherwise, the invocation fails.

## Parameters

### `plRingMode` [out]

Phone ring mode.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[put_RingMode](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-put_ringmode)