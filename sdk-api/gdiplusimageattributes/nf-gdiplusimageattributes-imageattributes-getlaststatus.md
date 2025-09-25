# ImageAttributes::GetLastStatus

## Description

The **ImageAttributes::GetLastStatus** method returns a value that indicates the nature of this [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **ImageAttributes::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object have failed since the previous call to **ImageAttributes::GetLastStatus**, then **ImageAttributes::GetLastStatus** returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status).

If at least one method invoked on this
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object has failed since the previous call to **ImageAttributes::GetLastStatus**, then **ImageAttributes::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **ImageAttributes::GetLastStatus** immediately after constructing an
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object to determine whether the constructor succeeded.

The first time you call the **ImageAttributes::GetLastStatus** method of an
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) if the constructor succeeded and all methods invoked so far on the
**ImageAttributes** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

## See also

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)