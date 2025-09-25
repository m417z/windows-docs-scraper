# IAutoCompleteDropDown::GetDropDownStatus

## Description

Gets the current display status of the autocomplete drop-down list.

## Parameters

### `pdwFlags` [out]

Type: **DWORD***

A pointer to a value indicating whether the autocomplete drop-down list is currently displayed. This parameter can be **NULL** on entry if this information is not needed. The following values are recognized as the target of this pointer.

#### (0x0000)

The list is not visible.

#### ACDD_VISIBLE (0x0001)

The list is visible.

### `ppwszString` [out]

Type: **LPWSTR***

A pointer to a buffer containing the first select item in the drop-down list, if the value pointed to by *pdwFlags* is **ACDD_VISIBLE**. This value can be **NULL** on entry if this information is not needed.

If *pdwFlags* is zero on exit, then this value will be **NULL**.

If this value is not **NULL** on exit, the buffer it points to must be freed using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when it is no longer needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAutoCompleteDropDown](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iautocompletedropdown)