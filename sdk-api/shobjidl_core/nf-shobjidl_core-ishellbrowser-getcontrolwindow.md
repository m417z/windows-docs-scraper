# IShellBrowser::GetControlWindow

## Description

Gets the window handle to a browser control.

## Parameters

### `id`

Type: **UINT**

The control handle that is being requested. This parameter can be one of the following values:

#### FCW_TOOLBAR

Retrieves the window handle to the browser's toolbar.

#### FCW_STATUS

Retrieves the window handle to the browser's status bar.

#### FCW_TREE

Retrieves the window handle to the browser's tree view.

#### FCW_PROGRESS

Retrieves the window handle to the browser's progress bar.

### `phwnd`

Type: **HWND***

The address of the window handle to the Windows Explorer control.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

**GetControlWindow** is used so views can directly manipulate the browser's controls. **FCW_TREE** should be used only to determine if the tree is present.

### Notes to Calling Applications

**GetControlWindow** is used to manipulate and test the state of the control windows. Do not send messages directly to these controls; instead, use [IShellBrowser::SendControlMsg](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-sendcontrolmsg). Be prepared for this method to return **NULL**. Later versions of Windows Explorer may not include a toolbar, status bar, or tree window.

### Notes to Implementers

**GetControlWindow** returns the window handle to these controls if they exist in your implementation.

See also [IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)