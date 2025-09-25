# IShellView::DestroyViewWindow

## Description

Destroys the view window.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

Windows Explorer calls this method when a folder window or Windows Explorer is being closed.

### Notes to Implementers

Clean up all states that represent the view, including the window and any other associated resources.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)