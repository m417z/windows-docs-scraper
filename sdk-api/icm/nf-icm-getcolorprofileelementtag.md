## Description

Retrieves the tag name specified by *dwIndex* in the tag table of a given International Color Consortium (ICC) color profile, where *dwIndex* is a one-based index into that table.

## Parameters

### `hProfile`

Specifies a handle to the ICC color profile in question.

### `dwIndex`

Specifies the one-based index of the tag to retrieve.

### `pTag`

Pointer to a variable in which the tag name is to be placed.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function will fail if *hProfile* is not a valid ICC profile.

**GetColorProfileElementTag** can be used to enumerate all tags in a profile after getting the number of tags in the profile using [**GetCountColorProfileElements**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-getcountcolorprofileelements).

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP; because profile elements are implicitly associated with, and hard coded to, ICC tag types and there exist many robust XML parsing libraries.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)