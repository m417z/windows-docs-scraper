# LVFINDINFOW structure

## Description

Contains information used when searching for a list-view item. This structure is identical to LV_FINDINFO but has been renamed to fit standard naming conventions.

## Members

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type of search to perform. This member can be set to one or more of the following values:

| Value | Meaning |
| --- | --- |
| **LVFI_PARAM** | Searches for a match between this structure's **lParam** member and the **lParam** member of an item's [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure. |
| **LVFI_PARTIAL** | Checks to see if the item text begins with the string pointed to by the **psz** member. This value implies use of LVFI_STRING. |
| **LVFI_STRING** | Searches based on the item text. Unless additional values are specified, the item text of the matching item must exactly match the string pointed to by the **psz** member. However, the search is case-insensitive. |
| **LVFI_SUBSTRING** | **Windows Vista and later.** Equivalent to LVFI_PARTIAL. |
| **LVFI_WRAP** | Continues the search at the beginning if no match is found. If this flag is used by itself, it is assumed that a string search is wanted. |
| **LVFI_NEARESTXY** | Finds the item nearest to the position specified in the **pt** member, in the direction specified by the **vkDirection** member. This flag is supported only by large icon and small icon modes. If LVFI_NEARESTXY is specified, all other flags are ignored. |

### `psz`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Address of a null-terminated string to compare with the item text. It is valid only if LVFI_STRING or LVFI_PARTIAL is set in the **flags** member.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value to compare with the **lParam** member of a list-view item's [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure. It is valid only if LVFI_PARAM is set in the **flags** member.

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure with the initial search position. It is valid only if LVFI_NEARESTXY is set in the **flags** member.

### `vkDirection`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Virtual key code that specifies the direction to search. The following codes are supported:

* VK_LEFT
* VK_RIGHT
* VK_UP
* VK_DOWN
* VK_HOME
* VK_END
* VK_PRIOR
* VK_NEXT

This member is valid only if LVFI_NEARESTXY is set in the **flags** member.

## Remarks

> [!NOTE]
> The commctrl.h header defines LVFINDINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).