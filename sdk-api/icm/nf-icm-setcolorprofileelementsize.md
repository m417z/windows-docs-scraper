## Description

Sets the size of a tagged element in an ICC color profile.

## Parameters

### `hProfile`

Specifies a handle to the ICC color profile in question.

### `tagType`

Identifies the tagged element.

### `pcbElement`

Specifies the size to set the tagged element to. If *cbSize* is zero, this function deletes the specified tagged element. If the tag is a reference, only the tag table entry is deleted, not the data.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function will fail if *hProfile* is not a valid ICC profile.

To create a new tagged element in a color profile, use **SetColorProfileElementSize** to set the size, then use [**SetColorProfileElement**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-setcolorprofileelement) to set the element value.

If the specified tag already exists in the profile, **SetColorProfileElementSize** changes the size of the element by truncating it or adding zeroes at the end as the case may be.

If the specified tag already exists and is a reference to another tag, **SetColorProfileElementSize** creates a new data area for the tag that is not shared.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP; because profile elements are implicitly associated with and hard coded to ICC tag types and there exist many robust XML parsing libraries.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [SetColorProfileElement](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-setcolorprofileelement)