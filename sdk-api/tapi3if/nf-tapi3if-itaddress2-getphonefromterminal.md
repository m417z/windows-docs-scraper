# ITAddress2::GetPhoneFromTerminal

## Description

The
**GetPhoneFromTerminal** method returns the phone object associated with the terminal. Only one phone can be associated with a terminal.

## Parameters

### `pTerminal` [in]

Pointer to the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface.

### `ppPhone` [out]

Pointer to the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITAddress2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress2)

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)