# ITPhone::get_ButtonText

## Description

The
**get_ButtonText** method retrieves the button text associated with a particular button.

The application must call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before invoking this method; otherwise, the invocation fails. See the TAPI 2.*x* documentation for more information about the concept of button text.

## Parameters

### `lButtonID` [in]

Button identifier.

### `ppButtonText` [out]

The **BSTR** representation of the button text. The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The **BSTR** argument should be deallocated by the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[put_ButtonText](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-put_buttontext)