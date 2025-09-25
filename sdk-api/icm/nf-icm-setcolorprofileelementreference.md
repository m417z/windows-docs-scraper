## Description

Creates in a specified ICC color profile a new tag that references the same data as an existing tag.

## Parameters

### `hProfile`

Specifies a handle to the ICC color profile in question.

### `newTag`

Identifies the new tag to create.

### `refTag`

Identifies the existing tag whose data is to be referenced by the new tag.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function will fail if *hProfile* is not a valid ICC profile.

If *newTag* already exists or *refTag* does not exist, **SetColorProfileElementReference** fails.

If the color profile was not opened with read/write permission, **SetColorProfileElementReference** fails.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP; because profile elements are implicitly associated with and hard coded to ICC tag types and there exist many robust XML parsing libraries.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)