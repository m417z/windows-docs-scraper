# IOleInPlaceSiteWindowless::AdjustRect

## Description

Adjusts a specified rectangle if it is entirely or partially covered by overlapping, opaque objects.

## Parameters

### `prc` [in, out]

The rectangle to be adjusted.

## Return value

This method returns S_OK if rectangle was adjusted successfully; meaning that the rectangle was not completely covered. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The rectangle was adjusted successfully. Note S_FALSE means that the rectangle was completely covered. Its width and height are now **NULL**. |

## Remarks

The main use of this method is to adjust the size of the caret. An object willing to create a caret should submit the caret rectangle to its site object by calling this method and using the adjusted rectangle returned from it for the caret. If the caret is entirely hidden, this method will return S_FALSE and the caret should not be shown at all in this case.

In a situation where objects are overlapping this method should return the largest rectangle that is fully visible.

This method can also be used to figure whether a point or a rectangular area is visible or hidden by overlapping objects.

## See also

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)