## Description

Sets the header data in a specified ICC color profile.

## Parameters

### `hProfile`

Specifies a handle to the ICC color profile in question.

### `pHeader`

Pointer to the profile header data to write to the specified profile.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function will fail if *hProfile* is not a valid ICC profile.

If the color profile was not opened with read/write permission, **SetColorProfileHeader** fails.

**SetColorProfileHeader** overwrites the current header in the ICC profile.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP; because profile elements are implicitly associated with and hard coded to ICC tag types and there exist many robust XML parsing libraries.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [PROFILEHEADER](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-profileheader)