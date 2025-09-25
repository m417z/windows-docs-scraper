# IOleControlSite::ShowPropertyFrame

## Description

Instructs a container to display a property sheet for the control embedded in this site.

## Return value

This method can return the standard return value E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The container does not need to show property pages itself. |

## Remarks

A control must always call this method in the container first when it intends to show its own property pages. Calling this method gives the container a chance to have those property pages work with the container's extended controls. The container may include its own property pages as well in such cases, which doesn't affect the control at all. If the container does not implement this method or if it returns a failure of any kind, the control can show its property pages directly. Otherwise, the container has shown the pages.

## See also

[IOleControlSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrolsite)