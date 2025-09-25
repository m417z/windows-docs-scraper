# IOleClientSite::OnShowWindow

## Description

Notifies a container when an embedded object's window is about to become visible or invisible. This method does not apply to an object that is activated in place and therefore has no window separate from that of its container.

## Parameters

### `fShow` [in]

Indicates whether an object's window is open (TRUE) or closed (FALSE).

## Return value

This method returns S_OK on success.

## Remarks

An embedded object calls **OnShowWindow** to keep its container informed when the object is open in a window. This window may or may not be currently visible to the end user. The container uses this information to shade the object's client site when the object is displayed in a window, and to remove the shading when the object is not. A shaded object, having received this notification, knows that it already has an open window and therefore can respond to being double-clicked by bringing this window quickly to the top, instead of launching its application in order to obtain a new one.

## See also

[IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite)