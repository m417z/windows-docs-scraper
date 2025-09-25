# FINDEX_INFO_LEVELS enumeration

## Description

Defines values that are used with the
[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) function to specify the information
level of the returned data.

## Constants

### `FindExInfoStandard`

The [FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) function retrieves a
standard set of attribute information. The data is returned in a
[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure.

### `FindExInfoBasic`

The [FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) function does not query the short file name, improving overall enumeration speed. The data is returned in a
[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure, and the **cAlternateFileName**
member is always a **NULL** string.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7.

### `FindExInfoMaxInfoLevel`

This value is used for validation. Supported values are less than this value.

## See also

[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa)

[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa)