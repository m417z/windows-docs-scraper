# LVGROUP structure

## Description

Used to set and retrieve groups.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of this structure, in bytes.

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask that specifies which members of the structure are valid input. One or more of the following values:

| Value | Meaning |
| --- | --- |
| **LVGF_NONE** | No other items are valid. |
| **LVGF_HEADER** | **pszHeader** and **cchHeader** members are valid. |
| **LVGF_FOOTER** | **pszFooter** and **cchFooter** members are valid. |
| **LVGF_STATE** | **state** and **stateMask** members are valid. |
| LVGF_ALIGN | **uAlign** member is valid. |
| LVGF_GROUPID | **iGroupId** member is valid. |
| LVGF_SUBTITLE | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **pszSubtitle** member is valid. |
| LVGF_TASK | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **pszTask** member is valid. |
| LVGF_DESCRIPTIONTOP | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **pszDescriptionTop** member is valid. |
| LVGF_DESCRIPTIONBOTTOM | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **pszDescriptionBottom** member is valid. |
| LVGF_TITLEIMAGE | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **iTitleImage** member is valid. |
| LVGF_EXTENDEDIMAGE | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **iExtendedImage** member is valid. |
| LVGF_ITEMS | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **cItems** member is valid. |
| LVGF_SUBSET | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **pszSubsetTitle** member is valid. |
| LVGF_SUBSETITEMS | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **cchSubsetTitle** member is valid. |

### `pszHeader`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that contains the header text when item information is being set. If group information is being retrieved, this member specifies the address of the buffer that receives the header text.

### `cchHeader`

Type: **int**

Size in **TCHAR**s of the buffer pointed to by the **pszHeader** member. If the structure is not receiving information about a group, this member is ignored.

### `pszFooter`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that contains the footer text when item information is being set. If group information is being retrieved, this member specifies the address of the buffer that receives the footer text.

### `cchFooter`

Type: **int**

Size in **TCHAR**s of the buffer pointed to by the **pszFooter** member. If the structure is not receiving information about a group, this member is ignored.

### `iGroupId`

Type: **int**

ID of the group.

### `stateMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask used with [LVM_GETGROUPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvm-getgroupinfo) and [LVM_SETGROUPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvm-setgroupinfo) to specify which flags in the **state** value are being retrieved or set.

### `state`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag that can have one of the following values:

| Value | Meaning |
| --- | --- |
| LVGS_NORMAL | Groups are expanded, the group name is displayed, and all items in the group are displayed. |
| LVGS_COLLAPSED | The group is collapsed. |
| LVGS_HIDDEN | The group is hidden. |
| LVGS_NOHEADER | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The group does not display a header. |
| LVGS_COLLAPSIBLE | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The group can be collapsed. |
| LVGS_FOCUSED | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The group has keyboard focus. |
| LVGS_SELECTED | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The group is selected. |
| LVGS_SUBSETED | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The group displays only a portion of its items. |
| LVGS_SUBSETLINKFOCUSED | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The subset link of the group has keyboard focus. |

### `uAlign`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates the alignment of the header or footer text for the group. It can have one or more of the following values. Use one of the header flags. Footer flags are optional.

| Value | Meaning |
| --- | --- |
| LVGA_FOOTER_CENTER | Footer text is centered horizontally in the window. |
| LVGA_FOOTER_LEFT | Footer text is aligned at the left of the window. |
| LVGA_FOOTER_RIGHT | Footer text is aligned at the right of the window. |
| LVGA_HEADER_CENTER | Header text is centered horizontally in the window. |
| LVGA_HEADER_LEFT | Header text is aligned at the left of the window. |
| LVGA_HEADER_RIGHT | Header text is aligned at the right of the window. |

### `pszSubtitle`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that contains the subtitle text when item information is being set. If group information is being retrieved, this member specifies the address of the buffer that receives the subtitle text. This element is drawn under the header text.

### `cchSubtitle`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size, in **TCHAR**s, of the buffer pointed to by the **pszSubtitle** member. If the structure is not receiving information about a group, this member is ignored.

### `pszTask`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that contains the text for a task link when item information is being set. If group information is being retrieved, this member specifies the address of the buffer that receives the task text. This item is drawn right-aligned opposite the header text. When clicked by the user, the task link generates an [LVN_LINKCLICK](https://learn.microsoft.com/windows/desktop/Controls/lvn-linkclick) notification.

### `cchTask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size in **TCHAR**s of the buffer pointed to by the **pszTask** member. If the structure is not receiving information about a group, this member is ignored.

### `pszDescriptionTop`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that contains the top description text when item information is being set. If group information is being retrieved, this member specifies the address of the buffer that receives the top description text. This item is drawn opposite the title image when there is a title image, no extended image, and **uAlign**==**LVGA_HEADER_CENTER**.

### `cchDescriptionTop`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size in **TCHAR**s of the buffer pointed to by the **pszDescriptionTop** member. If the structure is not receiving information about a group, this member is ignored.

### `pszDescriptionBottom`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that contains the bottom description text when item information is being set. If group information is being retrieved, this member specifies the address of the buffer that receives the bottom description text. This item is drawn under the top description text when there is a title image, no extended image, and **uAlign**==**LVGA_HEADER_CENTER**.

### `cchDescriptionBottom`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size in **TCHAR**s of the buffer pointed to by the **pszDescriptionBottom** member. If the structure is not receiving information about a group, this member is ignored.

### `iTitleImage`

Type: **int**

Index of the title image in the control imagelist.

### `iExtendedImage`

Type: **int**

Index of the extended image in the control imagelist.

### `iFirstItem`

Type: **int**

Read-only.

### `cItems`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Read-only in non-owner data mode.

### `pszSubsetTitle`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**NULL** if group is not a subset. Pointer to a null-terminated string that contains the subset title text when item information is being set. If group information is being retrieved, this member specifies the address of the buffer that receives the subset title text.

### `cchSubsetTitle`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size in **TCHAR**s of the buffer pointed to by the **pszSubsetTitle** member. If the structure is not receiving information about a group, this member is ignored.

## Remarks

All strings returned in this structure should be treated as read-only.

The creation of subsets is not currently supported, and **pszSubsetTitle** cannot be set by applications.