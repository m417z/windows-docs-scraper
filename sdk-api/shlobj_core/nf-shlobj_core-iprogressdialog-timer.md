# IProgressDialog::Timer

## Description

Resets the progress dialog box timer to zero.

## Parameters

### `dwTimerAction` [in]

Type: **DWORD**

Flags that indicate the action to be taken by the timer. One of the following values:

#### PDTIMER_RESET

Resets the timer to zero. Progress will be calculated from the time this method is called.

#### PDTIMER_PAUSE

Progress has been suspended.

#### PDTIMER_RESUME

Progress has been resumed.

### `pvResevered`

Type: **LPCVOID**

Reserved. Set to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The timer is used to estimate the remaining time. It is started when your application calls [IProgressDialog::StartProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iprogressdialog-startprogressdialog). Unless your application will start immediately, it should call **Timer** just before starting the operation. This practice ensures that the time estimates will be as accurate as possible. This method should not be called after the first call to [IProgressDialog::SetProgress](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iprogressdialog-setprogress).

## See also

[IProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iprogressdialog)