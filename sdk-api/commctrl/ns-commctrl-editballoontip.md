# EDITBALLOONTIP structure

## Description

Contains information about a balloon tip associated with a button control.

## Members

### `cbStruct`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **DWORD** that contains the size, in bytes, of the structure.

### `pszTitle`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a Unicode string that contains the title of the balloon tip.

### `pszText`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a Unicode string that contains the balloon tip text.

### `ttiIcon`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value of type **INT** that specifies the type of icon to associate with the balloon tip. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TTI_ERROR** | Use the error icon. |
| **TTI_INFO** | Use the information icon. |
| **TTI_NONE** | Use no icon. |
| **TTI_WARNING** | Use the warning icon. |
| **TTI_INFO_LARGE** | Use the large information icon. This is assumed to be an HICON value. |
| **TTI_WARNING_LARGE** | Use the large warning icon. This is assumed to be an HICON value. |
| **TTI_ERROR_LARGE** | Use the large error icon. This is assumed to be an HICON value. |

## See also

**Conceptual**

[EM_SHOWBALLOONTIP](https://learn.microsoft.com/windows/desktop/Controls/em-showballoontip)

[Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/edit-controls)

[Edit_ShowBalloonTip](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-edit_showballoontip)

**Reference**