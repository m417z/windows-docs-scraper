# ITPhone::GetPhoneCapsBuffer

## Description

The
**GetPhoneCapsBuffer** method gets a buffer capability/information about the phone, based on the
[PHONECAPS_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_buffer) enum passed in.

This method is intended for C/C++ applications. Visual Basic and scripting applications must use the
[get_PhoneCapsBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_phonecapsbuffer) method.

## Parameters

### `pcbCaps` [in]

The
[PHONECAPS_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_buffer) descriptor for the phone capability.

### `pdwSize` [out]

Size of the buffer, in bytes.

### `ppPhoneCapsBuffer` [out]

Pointer to the buffer containing the values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)