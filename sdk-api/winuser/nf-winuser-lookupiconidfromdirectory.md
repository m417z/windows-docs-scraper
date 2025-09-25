# LookupIconIdFromDirectory function

## Description

Searches through icon (**RT_GROUP_ICON**) or cursor (**RT_GROUP_CURSOR**) resource data for the icon or cursor that best fits the current display device.

To specify a desired height or width, use the [LookupIconIdFromDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectoryex) function. This function calls it by passing zero in the **cxDesired**/**cyDesired** parameters.

## Parameters

### `presbits` [in]

Type: **PBYTE**

The icon or cursor directory data. Because this function does not validate the resource data, it causes a general protection (GP) fault or returns an undefined value if *presbits* is not pointing to valid resource data.

### `fIcon` [in]

Type: **BOOL**

Indicates whether an icon or a cursor is sought. If this parameter is **TRUE**, the function is searching for an icon; if the parameter is **FALSE**, the function is searching for a cursor.

## Return value

Type: **int**

If the function succeeds, the return value is an integer resource identifier for the icon (**RT_ICON**) or cursor (**RT_CURSOR**) that best fits the current display device.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A resource file of type **RT_GROUP_ICON** (**RT_GROUP_CURSOR** indicates cursors) contains icon (or cursor) data in several device-dependent and device-independent formats. **LookupIconIdFromDirectory** searches the resource file for the icon (or cursor) that best fits the current display device and returns its integer identifier. The [FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea) and [FindResourceEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourceexa) functions use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro with this identifier to locate the resource in the module.

The icon directory is loaded from a resource file with resource type **RT_GROUP_ICON** (or **RT_GROUP_CURSOR** for cursors), and an integer resource name for the specific icon to be loaded. **LookupIconIdFromDirectory** returns an integer identifier that is the resource name of the icon that best fits the current display device.

The [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona), [LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora), and [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) functions use this function to search the specified resource data for the icon or cursor that best fits the current display device.

## See also

**Conceptual**

[CreateIconFromResource](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresource)

[CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect)

[FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea)

[FindResourceEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourceexa)

[GetIconInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-geticoninfo)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)

[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)

[LookupIconIdFromDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectoryex)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Reference**