# SdbInitDatabase function

Opens the shim database.

## Parameters

*dwFlags* \[in\]

This parameter specifies the format of the path in the *pszDatabasePath* parameter. It can be one of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------|
|

**HID\_DOS\_PATHS**

0x00000001

| An MS-DOS style path.<br> |
|

**HID\_DATABASE\_FULLPATH**

0x00000002

| A full path.<br> |
|

**HID\_NO\_DATABASE**

0x00000004

| The *pszDatabasePath* parameter is ignored and no database is opened.<br> |
|

**HID\_DATABASE\_TYPE\_MASK**

0xF00F0000

| This parameter specifies a predefined database. The *pszDatabasePath* parameter is ignored.<br> |

If *dwFlags* contains **HID\_DATA\_TYPE\_MASK**, this parameter can also include one of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------|
|

**SDB\_DATABASE\_MAIN\_SHIM**

0x80030000

| Application shim database.<br> |
|

**SDB\_DATABASE\_MAIN\_MSI**

0x80020000

| MSI database.<br> |
|

**SDB\_DATABASE\_MAIN\_DRIVERS**

0x80040000

| Database of drivers to be blocked.<br> |

*pszDatabasePath* \[in\]

The path to the database. This parameter can be **NULL** if the *dwFlags* parameter specifies a predefined database.

## Return value

The function returns a handle to the opened database.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbGetAppPatchDir**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetapppatchdir)

[**SdbGetMatchingExe**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetmatchingexe)

[**SdbReleaseMatchingExe**](https://learn.microsoft.com/windows/win32/devnotes/sdbreleasematchingexe)

[**SdbTagRefToTagID**](https://learn.microsoft.com/windows/win32/devnotes/sdbtagreftotagid)

