# ITPhone::get_PhoneCapsBuffer

## Description

The
**get_PhoneCapsBuffer** method gets a buffer capability/information about the phone, based on the
[PHONECAPS_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_buffer) enum passed in.

This method is intended for Visual Basic and scripting applications. C/C++ applications must use the
[GetPhoneCapsBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-getphonecapsbuffer) method.

## Parameters

### `pcbCaps` [in]

The
[PHONECAPS_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_buffer) descriptor for the phone capability.

### `pVarBuffer` [out]

Pointer to VARIANT containing the capability value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)