# IOleInPlaceSiteWindowless::GetCapture

## Description

Called by an in-place active, windowless object to determine whether it still has the mouse capture.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The object does not currently have the mouse capture. |

## Remarks

As an alternative to calling this method, the object can cache information about whether it has the mouse capture.

## See also

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)