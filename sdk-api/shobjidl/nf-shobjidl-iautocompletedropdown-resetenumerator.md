# IAutoCompleteDropDown::ResetEnumerator

## Description

Forces the autocomplete object to refresh its list of suggestions when the list is visible.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The drop-down list is always rebuilt before it is displayed, so there is no reason to use this method unless the drop-down list is currently visible.

## See also

[IAutoCompleteDropDown](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iautocompletedropdown)