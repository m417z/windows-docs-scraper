# IShellView::Refresh

## Description

Refreshes the view's contents in response to user input.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

Tells the view to refresh its contents, revalidating any view information it has.

### Note to Calling Applications

Windows Explorer calls this method when the F5 key is pressed on an already open view.

### Notes to Implementers

Refill the view by going to any underlying storage for the contents.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)