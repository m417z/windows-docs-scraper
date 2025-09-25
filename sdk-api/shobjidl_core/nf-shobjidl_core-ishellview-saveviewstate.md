# IShellView::SaveViewState

## Description

Saves the Shell's view settings so the current state can be restored during a subsequent browsing session.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

The Shell view obtains a view stream by calling the [GetViewStateStream](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-getviewstatestream) method and stores the current view state in that stream.

### Note to Calling Applications

Windows Explorer calls this method when it wants to save the view state for a view.

### Notes to Implementers

Be sure to make the format of the data stored in the stream robust enough that different versions of the implementation can read it without error.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)