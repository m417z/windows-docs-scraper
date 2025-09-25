# GetMenuStringA function

## Description

Copies the text string of the specified menu item into the specified buffer.

**Note** The **GetMenuString** function has been superseded. Use the [GetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuiteminfoa) function to retrieve the menu item text.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu.

### `uIDItem` [in]

Type: **UINT**

The menu item to be changed, as determined by the *uFlag* parameter.

### `lpString` [out, optional]

Type: **LPTSTR**

The buffer that receives the null-terminated string. If the string is as long or longer than *lpString*, the string is truncated and the terminating null character is added. If *lpString* is **NULL**, the function returns the length of the menu string.

### `cchMax` [in]

Type: **int**

The maximum length, in characters, of the string to be copied. If the string is longer than the maximum specified in the *nMaxCount* parameter, the extra characters are truncated. If *nMaxCount* is 0, the function returns the length of the menu string.

### `flags` [in]

Type: **UINT**

Indicates how the *uIDItem* parameter is interpreted. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **MF_BYCOMMAND**<br><br>0x00000000L | Indicates that *uIDItem* gives the identifier of the menu item. If neither the **MF_BYCOMMAND** nor **MF_BYPOSITION** flag is specified, the **MF_BYCOMMAND** flag is the default flag. |
| **MF_BYPOSITION**<br><br>0x00000400L | Indicates that *uIDItem* gives the zero-based relative position of the menu item. |

## Return value

Type: **int**

If the function succeeds, the return value specifies the number of characters copied to the buffer, not including the terminating null character.

If the function fails, the return value is zero.

If the specified item is not of type **MIIM_STRING** or **MFT_STRING**, then the return value is zero.

## Remarks

The *nMaxCount* parameter must be one larger than the number of characters in the text string to accommodate the terminating null character.

If *nMaxCount* is 0, the function returns the length of the menu string.

### Security Warning

The *lpString* parameter is a **TCHAR** buffer, and *nMaxCount* is the length of the menu string in characters. Sizing these parameters incorrectly can cause truncation of the string, leading to possible loss of data.

#### Examples

For an example, see [Creating User Editable Accelerators](https://learn.microsoft.com/windows/desktop/menurc/using-keyboard-accelerators).

> [!NOTE]
> The winuser.h header defines GetMenuString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetMenuItemID](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuitemid)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**