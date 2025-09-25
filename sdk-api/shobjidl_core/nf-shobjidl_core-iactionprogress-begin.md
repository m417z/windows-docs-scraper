# IActionProgress::Begin

## Description

Called when an action has begun that requires its progress be displayed to the user.

## Parameters

### `action` [in]

Type: **[SPACTION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-spaction)**

The action being performed. See [SPACTION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-spaction) for a list of acceptable values.

### `flags` [in]

Type: **[SPBEGINF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_spbeginf)**

Optional flags that request certain UI operations be enabled or disabled. See [SPBEGINF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_spbeginf) for a list of acceptable values.

## Return value

Type: **HRESULT**

Return S_OK if successful, or an error value otherwise.

## Remarks

This method should be called when an action is beginning. The values of *action* and *flags* may be used to determine how to draw the UI that will be displayed to the user, or how to interpret or filter certain user actions associated with the action. When the action has completed, [IActionProgress::End](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iactionprogress-end) should be called.

## See also

[IActionProgress](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogress)

[IActionProgress::End](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iactionprogress-end)

[SPACTION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-spaction)

[SPBEGINF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_spbeginf)