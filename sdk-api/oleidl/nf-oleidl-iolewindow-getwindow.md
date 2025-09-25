# IOleWindow::GetWindow

## Description

Retrieves a handle to one of the windows participating in in-place activation (frame, document, parent, or in-place object window).

## Parameters

### `phwnd` [out]

A pointer to a variable that receives the window handle.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The object is windowless. |
| **E_INVALIDARG** | The specified *fEnterMode* value is not valid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

Five types of windows comprise the windows hierarchy. When a object is active in place, it has access to some or all of these windows.

| Window | Description |
| --- | --- |
| Frame | The outermost main window where the container application's main menu resides. |
| Document | The window that displays the compound document containing the embedded object to the user. |
| Pane | The subwindow of the document window that contains the object's view. Applicable only for applications with split-pane windows. |
| Parent | The container window that contains that object's view. The object application installs its window as a child of this window. |
| In-place | The window containing the active in-place object. The object application creates this window and installs it as a child of its hatch window, which is a child of the container's parent window. |

Each type of window has a different role in the in-place activation architecture. However, it is not necessary to employ a separate physical window for each type. Many container applications use the same window for their frame, document, pane, and parent windows.

## See also

[IOleWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolewindow)