# IAutoComplete2::SetOptions

## Description

Sets the current autocomplete options.

## Parameters

### `dwFlag` [in]

Type: **DWORD**

One or more flags from the [AUTOCOMPLETEOPTIONS](https://learn.microsoft.com/windows/desktop/api/shldisp/ne-shldisp-autocompleteoptions) enumeration that specify autocomplete options.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The TAB key is disabled by default because it is typically used to navigate from control to control, not within a control. If you set the [ACO_USETAB](https://learn.microsoft.com/windows/desktop/api/shldisp/ne-shldisp-autocompleteoptions) flag in *dwFlag*, users can navigate to a string in the drop-down list by pressing the TAB key. If the drop-down list is closed, the TAB key allows the user to navigate from control to control, as usual. The user can close the drop-down list by pressing the ESC key.

## See also

[IAutoComplete2](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-iautocomplete2)

[IAutoComplete2::GetOptions](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-iautocomplete2-getoptions)