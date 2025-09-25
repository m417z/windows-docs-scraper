# IProgressDialog::StartProgressDialog

## Description

Starts the progress dialog box.

## Parameters

### `hwndParent` [in]

Type: **HWND**

A handle to the dialog box's parent window.

### `punkEnableModless`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Reserved. Set to **NULL**.

### `dwFlags`

Type: **DWORD**

Flags that control the operation of the progress dialog box. A combination of the following values:

#### PROGDLG_NORMAL

Normal progress dialog box behavior.

#### PROGDLG_MODAL

The progress dialog box will be modal to the window specified by *hwndParent*. By default, a progress dialog box is modeless.

#### PROGDLG_AUTOTIME

Automatically estimate the remaining time and display the estimate on line 3. If this flag is set, [IProgressDialog::SetLine](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iprogressdialog-setline) can be used only to display text on lines 1 and 2.

#### PROGDLG_NOTIME

Do not show the "time remaining" text.

#### PROGDLG_NOMINIMIZE

Do not display a minimize button on the dialog box's caption bar.

#### PROGDLG_NOPROGRESSBAR

Do not display a progress bar. Typically, an application can quantitatively determine how much of the operation remains and periodically pass that value to [IProgressDialog::SetProgress](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iprogressdialog-setprogress). The progress dialog box uses this information to update its progress bar. This flag is typically set when the calling application must wait for an operation to finish, but does not have any quantitative information it can use to update the dialog box.

#### PROGDLG_MARQUEEPROGRESS

**Windows Vista and later.** Sets the progress bar to marquee mode. This causes the progress bar to scroll horizontally, similar to a marquee display. Use this when you wish to indicate that progress is being made, but the time required for the operation is unknown.

#### PROGDLG_NOCANCEL

**Windows Vista and later.** Do not display a cancel button. The operation cannot be canceled. Use this only when absolutely necessary.

### `pvResevered`

Type: **LPCVOID**

Reserved. Set to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iprogressdialog)