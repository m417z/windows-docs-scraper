# ICommDlgBrowser2::GetViewFlags

## Description

Called when the view must determine if special customization needs to be made for the common dialog browser.

## Parameters

### `pdwFlags`

Type: **DWORD***

A pointer to a **DWORD** value that controls the behavior of the view when in common dialog mode.

#### CDB2GVF_SHOWALLFILES (0x00000001)

0x00000001. All files, including hidden and system files, should be shown. In Windows XP, this is the only recognized flag.

#### CDB2GVF_ISFILESAVE (0x00000002)

0x00000002. This browser is designated to choose a file to save.

#### CDB2GVF_ALLOWPREVIEWPANE (0x00000004)

0x00000004. Not used.

#### CDB2GVF_NOSELECTVERB (0x00000008)

0x00000008. Do not show a "`select`" verb on an item's context menu.

#### CDB2GVF_NOINCLUDEITEM (0x00000010)

0x00000010. [IncludeObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icommdlgbrowser-includeobject) should not be called.

#### CDB2GVF_ISFOLDERPICKER (0x00000020)

0x00000020. This browser is designated to pick folders.

#### CDB2GVF_ADDSHIELD (0x00000040)

0x00000040. **Windows 7 and later**. Displays a UAC shield on the selected item when CDB2GVF_NOSELECTVERB is not specified.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICommDlgBrowser2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icommdlgbrowser2)