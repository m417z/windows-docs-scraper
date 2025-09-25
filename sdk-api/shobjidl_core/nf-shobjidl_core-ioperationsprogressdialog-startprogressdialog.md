# IOperationsProgressDialog::StartProgressDialog

## Description

Starts the specified progress dialog.

## Parameters

### `hwndOwner` [in]

Type: **HWND**

A handle to the parent window.

### `flags` [in]

Type: **DWORD**

Flags that customize the operation. Note that these flags are declared in Shlobj.h. A combination of the following values:

#### PROGDLG_NORMAL (0x00000000)

Default, normal progress dialog behavior.

#### PROGDLG_MODAL (0x00000001)

The dialog is modal to its *hwndOwner*. The default setting is modeless.

#### PROGDLG_AUTOTIME (0x00000002)

Update "Line3" text with the time remaining. This flag does not need to be implicitly set because progress dialogs started by **IOperationsProgressDialog::StartProgressDialog** automatically display the time remaining.

#### PROGDLG_NOTIME (0x00000004)

Do not show the time remaining. We do not recommend setting this flag through [IOperationsProgressDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ioperationsprogressdialog) because it goes against the purpose of the dialog.

#### PROGDLG_NOMINIMIZE (0x00000008)

Do not display the minimize button.

#### PROGDLG_NOPROGRESSBAR (0x00000010)

Do not display the progress bar.

#### PROGDLG_MARQUEEPROGRESS (0x00000020)

This flag is invalid in this method. To set the progress bar to marquee mode, use the flags in [IOperationsProgressDialog::SetMode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ioperationsprogressdialog-setmode).

#### PROGDLG_NOCANCEL (0x00000040)

Do not display a cancel button because the operation cannot be canceled. Use this value only when absolutely necessary.

#### OPPROGDLG_DEFAULT (0x00000000)

**Windows 7 and later**. Indicates default, normal operation progress dialog behavior.

#### OPPROGDLG_ENABLEPAUSE (0x00000080)

Display a pause button. Use this only in situations where the operation can be paused.

#### OPPROGDLG_ALLOWUNDO (0x00000100)

The operation can be undone through the dialog. The **Stop** button becomes **Undo**. If pressed, the **Undo** button then reverts to **Stop**.

#### OPPROGDLG_DONTDISPLAYSOURCEPATH (0x00000200)

Do not display the path of source file in the progress dialog.

#### OPPROGDLG_DONTDISPLAYDESTPATH (0x00000400)

Do not display the path of the destination file in the progress dialog.

#### OPPROGDLG_NOMULTIDAYESTIMATES (0x00000800)

**Windows 7 and later**. If the estimated time to completion is greater than one day, do not display the time.

#### OPPROGDLG_DONTDISPLAYLOCATIONS (0x00001000)

**Windows 7 and later**. Do not display the location line in the progress dialog.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The progress dialog should be created on a separate thread than the file operation on which the dialog is reporting. If the dialog is running in the same thread as the file operation, progress messages are, at best, only sent as resources allow. Progress messages on the same thread as the file operation might not be sent at all.

Once **IOperationsProgressDialog::StartProgressDialog** is called, that instance of the **CLSID_ProgressDialog** object cannot be accessed by [IProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iprogressdialog), [IActionProgressDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogressdialog), or [IActionProgress](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogress). Although [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) can be used to access these interfaces, most of their methods cannot be invoked. [IOperationsProgressDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ioperationsprogressdialog) is the interface used to display the new progress dialog for the Windows Vista and later operations engine.