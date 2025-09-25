# INameSpaceTreeAccessible::OnGetDefaultAccessibilityAction

## Description

Gets the default accessibility action for a Shell item.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

### `pbstrDefaultAction` [out]

Type: **[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)***

When this method returns, contains a [BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) that specifies the default, accessibility action.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or E_OUTOFMEMORY otherwise.

## Remarks

This method is called when the default accessibility action for a Shell item is retrieved.