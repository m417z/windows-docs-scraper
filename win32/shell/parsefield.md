# ParseField function

\[The **ParseField** function is currently expected to be available for use in the next version of the Microsoft Windows operating system. It might be altered or unavailable in subsequent versions.\]

Reads a line from Setup.inf and extracts the specified field from the string.

## Parameters

*szData* \[in\]

Type: **LPCTSTR\***

A pointer to the line from Setup.inf.

*n* \[in\]

Type: **int**

**INT** that indicates which field to extract.

(0)

Indicates the field before an equals sign (=).

(1)

Indicates the first field.

*szBuf* \[in\]

Type: **LPTSTR\***

A pointer to the buffer that receives the extracted field.

*iBufLen* \[in\]

Type: **int**

**INT** that receives the size of the buffer that receives the extracted field.

## Return value

Type: **bool**

Returns **TRUE** if the function is successful and **FALSE** if it fails.

## Remarks

The fields in the string must be separated by commas.

Leading and trailing spaces are removed.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Util.h |
| Library<br> | Shell32.lib |
| DLL<br> | Shell32.dll (version 5.0 or later) |

