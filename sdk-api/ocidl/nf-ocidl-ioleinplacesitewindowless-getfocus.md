# IOleInPlaceSiteWindowless::GetFocus

## Description

Called by an in-place active, windowless object to determine whether it still has the keyboard focus.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The object does not currently have the keyboard focus. |

## Remarks

A windowless object calls this method to find out if it currently has the focus or not. As an alternative to calling this method, the object can cache information about whether it has the keyboard focus or not.

## See also

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)