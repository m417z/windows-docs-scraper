## Description

Copies data from a specified tagged profile element of a specified color profile into a buffer.

## Parameters

### `hProfile`

Specifies a handle to the International Color Consortium (ICC) color profile in question.

### `tag`

Identifies the tagged element from which to copy.

### `dwOffset`

Specifies the offset from the first byte of the tagged element data at which to begin copying.

### `pcbElement`

Pointer to a variable specifying the number of bytes to copy. On return, the variable contains the number of bytes actually copied.

### `pElement`

Pointer to a buffer into which the tagged element data is to be copied. The buffer must contain at least as many bytes as are specified by the variable pointed to by *pcbSize*. If the *pBuffer* pointer is set to **NULL**, the size of the entire tagged element data in bytes is returned in the memory location pointed to by *pcbSize,* and *dwOffset* is ignored. In this case, the function will return **FALSE**.

### `pbReference`

Points to a Boolean value that is set to **TRUE** if more than one tag in the color profile refers to the same data as the specified tag refers to, or **FALSE** if not.

## Return value

If this function succeeds, the return value is nonzero.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function will fail if *hProfile* is not a valid International Color Consortium (ICC) profile.

If the *pBuffer* pointer is set to **NULL**, the size of the entire tagged element data in bytes is returned in the variable pointed to by *pcbSize,* and *dwOffset* is ignored.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP; because profile elements are implicitly associated with, and hard coded to, ICC tag types and there exist many robust XML parsing libraries.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)