# ITaskbarList3::SetProgressValue

## Description

Displays or updates a progress bar hosted in a taskbar button to show the specific percentage completed of the full operation.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window whose associated taskbar button is being used as a progress indicator.

### `ullCompleted` [in]

Type: **ULONGLONG**

An application-defined value that indicates the proportion of the operation that has been completed at the time the method is called.

### `ullTotal` [in]

Type: **ULONGLONG**

An application-defined value that specifies the value *ullCompleted* will have when the operation is complete.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

### Determinate Progress Bar Lifecycle

An application first calls **SetProgressValue** to begin the display of a determinate progress bar, and then calls it again as needed to update the bar as the progress changes. When progress is complete, the application must call [SetProgressState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-setprogressstate) with the TBPF_NOPROGRESS flag to dismiss the progress bar.

### How the Taskbar Button Chooses the Progress Indicator for a Group

The taskbar button can show a progress indicator for only one window at a time. When the taskbar button represents a group and more than one of the windows in that group are broadcasting progress information, the taskbar button chooses its progress display based on the following state priority.

| Priority | State |
| --- | --- |
| 1 | TBPF_ERROR |
| 2 | TBPF_PAUSED |
| 3 | TBPF_NORMAL |
| 4 | TBPF_INDETERMINATE |

Unless [SetProgressState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-setprogressstate) has set a blocking state (TBPF_ERROR or TBPF_PAUSED) for the window, a call to **SetProgressValue** assumes the TBPF_NORMAL state even if it is not explicitly set. A call to **SetProgressValue** overrides and clears the TBPF_INDETERMINATE state.

In the case of a priority collision where two windows are broadcasting determinate progress, the window with the least progress is used.

Based on that priority, this determinate (specific percentage) progress indicator can be displayed in these cases:

* The taskbar button does not represent a group and the single window that it represents is broadcasting determinate progress information through this method.
* The taskbar button represents a group, only one window in that group is broadcasting progress information, and that window is broadcasting determinate progress information through this method.
* The taskbar button represents a group, multiple windows in that group are broadcasting progress information, at least one of those windows is broadcasting progress information through this method, and none of those windows has set the [TBPF_ERROR](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-setprogressstate) or **TBPF_PAUSED** state.

If a window in the group has set [TBPF_ERROR](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-setprogressstate) or **TBPF_PAUSED**, that state will be used for the button display. However, you can still make calls to **SetProgressValue** on other, unblocked windows in the group to update their progress in the background.

#### Examples

Here is an example of how an application could use [ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3) to display progress while it is performing operations.

```cpp
HRESULT CMyApp::ShowProgressInTaskbar(HWND hwnd, __in ITaskbarList3 *pTL)
{
    // Set the progress state of the button to indeterminate while you calculate
    // the number of operations to be performed.
    HRESULT hr = pTL->SetProgressState(hwnd, TBPF_INDETERMINATE);

    // Calculate the number of operations to perform.
    int cTotalOperations = _CalculateNumberOfOperationsToPerform();

    for (int i=0; i < cTotalOperations && SUCCEEDED(hr); i++)
    {
        // Update the progress. This call to SetProgressValue cancels the
        // indeterminate state and puts the button into normal progress mode.
        pTL->SetProgressValue(hwnd, i, cTotalOperations);

        // Do whatever operation your application needs to perform.
        hr = _PerformOperation(i);
    }

    // Tell the button that progress no longer needs to be displayed.
    pTL->SetProgressState(hwnd, TBPF_NOPROGRESS);

    return hr;
}
```

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[ITaskbarList3::SetProgressState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-setprogressstate)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)