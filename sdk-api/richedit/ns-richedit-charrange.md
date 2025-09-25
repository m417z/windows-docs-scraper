# CHARRANGE structure

## Description

Specifies a range of characters in a rich edit control.

If the **cpMin** and **cpMax** members are equal, the range is empty. The range includes everything if **cpMin** is 0 and **cpMax** is –1.

## Members

### `cpMin`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character position index immediately preceding the first character in the range.

### `cpMax`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character position immediately following the last character in the range.

## See also

[EM_EXGETSEL](https://learn.microsoft.com/windows/win32/controls/em-exgetsel)

[EM_EXSETSEL](https://learn.microsoft.com/windows/win32/controls/em-exsetsel)

**Reference**