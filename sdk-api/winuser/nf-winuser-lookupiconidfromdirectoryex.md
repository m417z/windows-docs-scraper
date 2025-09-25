# LookupIconIdFromDirectoryEx function

## Description

Searches through icon (**RT_GROUP_ICON**) or cursor (**RT_GROUP_CURSOR**) resource data for the icon or cursor that best fits the current display device.

If more than one image exists in resource group, this method uses the following criteria to choose an image:
- The image closest but not exceed the requested size is selected.
- If two or more images of that size are present, the one that matches the color depth of the display is chosen.
- If no images exactly match the color depth of the display, the image with the greatest color depth that does not exceed the color depth of the display is chosen. If all exceed the color depth, the one with the lowest color depth is chosen.

## Parameters

### `presbits` [in]

Type: **PBYTE**

The icon or cursor directory data. Because this function does not validate the resource data, it causes a general protection (GP) fault or returns an undefined value if *presbits* is not pointing to valid resource data.

### `fIcon` [in]

Type: **BOOL**

Indicates whether an icon or a cursor is sought. If this parameter is **TRUE**, the function is searching for an icon; if the parameter is **FALSE**, the function is searching for a cursor.

### `cxDesired` [in]

Type: **int**

The desired width, in pixels, of the icon. If this parameter is zero, the function uses the **SM_CXICON** or **SM_CXCURSOR** system metric value.

### `cyDesired` [in]

Type: **int**

The desired height, in pixels, of the icon. If this parameter is zero, the function uses the **SM_CYICON** or **SM_CYCURSOR** system metric value.

### `Flags` [in]

Type: **UINT**

A combination of the following values.

| Value | Meaning |
| --- | --- |
| **LR_DEFAULTCOLOR**<br><br>0x00000000 | Uses the default color format. |
| **LR_MONOCHROME**<br><br>0x00000001 | Creates a monochrome icon or cursor. |

## Return value

Type: **int**

If the function succeeds, the return value is an integer resource identifier for the icon (**RT_ICON**) or cursor (**RT_CURSOR**) that best fits the current display device.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A resource file of type **RT_GROUP_ICON** (**RT_GROUP_CURSOR** indicates cursors) contains icon (or cursor) data in several device-dependent and device-independent formats. **LookupIconIdFromDirectoryEx** searches the resource file for the icon (or cursor) that best fits the current display device and returns its integer identifier. The [FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea) and [FindResourceEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourceexa) functions use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro with this identifier to locate the resource in the module.

The icon directory is loaded from a resource file with resource type **RT_GROUP_ICON** (or **RT_GROUP_CURSOR** for cursors), and an integer resource name for the specific icon (**RT_ICON**) or cursor (**RT_CURSOR**) to be loaded.
[LoadResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource) and [CreateIconFromResourceEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createiconfromresourceex) functions may be used to create a corresponding icon or cursor.

The [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona), [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea), and [LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora) functions use this function to search the specified resource data for the icon or cursor that best fits the current display device. [LoadIconWithScaleDown](https://learn.microsoft.com/windows/win32/api/commctrl/nf-commctrl-loadiconwithscaledown) uses alternative search criteria for a best fit.

#### Examples

For an example, see [Sharing Icon Resources](https://learn.microsoft.com/windows/win32/menurc/using-icons#sharing-icon-resources).

## See also

**Conceptual**

[CreateIconFromResourceEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresourceex)

[CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect)

[FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea)

[FindResourceEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourceexa)

[GetIconInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-geticoninfo)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)

[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)

[LookupIconIdFromDirectory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectory)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Reference**