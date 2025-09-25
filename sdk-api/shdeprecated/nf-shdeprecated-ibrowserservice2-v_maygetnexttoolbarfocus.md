# IBrowserService2::v_MayGetNextToolbarFocus

## Description

Deprecated. Used when translating accelerators through [TranslateAcceleratorSB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-translateacceleratorsb) and in checking the cycle of focus between the view and the browser's toolbars.

## Parameters

### `lpMsg` [in]

Type: **LPMSG**

A pointer to a [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) that contains the keystroke message.

### `itbNext` [in]

Type: **UINT**

The index of the next toolbar, or ITB_VIEW if focus is shifting to the view.

### `citb` [in]

Type: **int**

The ID of the current toolbar with focus, or ITB_VIEW if the view has focus.

### `pptbi` [out]

Type: **LPTOOLBARITEM***

A pointer to a [TOOLBARITEM](https://learn.microsoft.com/windows/win32/api/shdeprecated/ns-shdeprecated-toolbaritem) structure that represents the toolbar receiving the focus.

### `phwnd` [out]

Type: **HWND***

A pointer to the handle of the window that contains the toolbar.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.