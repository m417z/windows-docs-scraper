# IAutoComplete2::GetOptions

## Description

Gets the current autocomplete options.

## Parameters

### `pdwFlag` [out]

Type: **DWORD***

One or more flags from the [AUTOCOMPLETEOPTIONS](https://learn.microsoft.com/windows/desktop/api/shldisp/ne-shldisp-autocompleteoptions) enumeration that indicate the options that are currently set.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAutoComplete2](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-iautocomplete2)

[IAutoComplete2::SetOptions](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-iautocomplete2-setoptions)