# INITCOMMONCONTROLSEX structure

## Description

Carries information used to load common control classes from the dynamic-link library (DLL). This structure is used with the [InitCommonControlsEx](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initcommoncontrolsex) function.

## Members

### `dwSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the structure, in bytes.

### `dwICC`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The set of bit flags that indicate which common control classes will be loaded from the DLL. This can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **ICC_ANIMATE_CLASS**<br><br>0x00000080 | Load animate control class. |
| **ICC_BAR_CLASSES**<br><br>0x00000004 | Load toolbar, status bar, trackbar, and tooltip control classes. |
| **ICC_COOL_CLASSES**<br><br>0x00000400 | Load rebar control class. |
| **ICC_DATE_CLASSES**<br><br>0x00000100 | Load date and time picker control class. |
| **ICC_HOTKEY_CLASS**<br><br>0x00000040 | Load hot key control class. |
| **ICC_INTERNET_CLASSES**<br><br>0x00000800 | Load IP address class. |
| **ICC_LINK_CLASS**<br><br>0x00008000 | Load a hyperlink control class. |
| **ICC_LISTVIEW_CLASSES**<br><br>0x00000001 | Load list-view and header control classes. |
| **ICC_NATIVEFNTCTL_CLASS**<br><br>0x00002000 | Load a native font control class. |
| **ICC_PAGESCROLLER_CLASS**<br><br>0x00001000 | Load pager control class. |
| **ICC_PROGRESS_CLASS**<br><br>0x00000020 | Load progress bar control class. |
| **ICC_STANDARD_CLASSES**<br><br>0x00004000 | Load one of the intrinsic User32 control classes. The user controls include button, edit, static, listbox, combobox, and scroll bar. |
| **ICC_TAB_CLASSES**<br><br>0x00000008 | Load tab and tooltip control classes. |
| **ICC_TREEVIEW_CLASSES**<br><br>0x00000002 | Load tree-view and tooltip control classes. |
| **ICC_UPDOWN_CLASS**<br><br>0x00000010 | Load up-down control class. |
| **ICC_USEREX_CLASSES**<br><br>0x00000200 | Load ComboBoxEx class. |
| **ICC_WIN95_CLASSES**<br><br>0x000000FF | Load animate control, header, hot key, list-view, progress bar, status bar, tab, tooltip, toolbar, trackbar, tree-view, and up-down control classes. |