# IBrowserService2::_SetFocus

## Description

Deprecated. Sets the focus on a toolbar or on the browser's view window. Called when translating accelerators through [TranslateAcceleratorSB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-translateacceleratorsb) or when [IBrowserService2::v_MayGetNextToolbarFocus](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice2-v_maygetnexttoolbarfocus) fails.

## Parameters

### `ptbi` [in]

Type: **LPTOOLBARITEM**

A pointer to a [TOOLBARITEM](https://learn.microsoft.com/windows/win32/api/shdeprecated/ns-shdeprecated-toolbaritem) structure that specifies a browser toolbar item.

### `hwnd` [in]

Type: **HWND**

The handle of the browser window in which the focus shift is taking place.

### `lpMsg` [in]

Type: **LPMSG**

A pointer to a [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) that contains a keystroke message that indicates an accelerator.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.