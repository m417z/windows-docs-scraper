# ITPhone::get_PhoneCapsLong

## Description

The
**get_PhoneCapsLong** method gets a **DWORD** capability of the phone, based on the
[PHONECAPS_LONG](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_long) enum passed in. The application does not have to call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before executing this method.

## Parameters

### `pclCap` [in]

The
[PHONECAPS_LONG](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_long) descriptor for the phone capability.

### `plCapability` [out]

Capability value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)