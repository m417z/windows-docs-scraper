# ITPhone::SetDisplay

## Description

The
**SetDisplay** method sets what will appear in a given row and column of the phone's display.

## Parameters

### `lRow` [in]

Display row.

### `lColumn` [in]

Display column.

### `bstrDisplay` [in]

The **BSTR** representation of the value to display.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[get_Display](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_display)