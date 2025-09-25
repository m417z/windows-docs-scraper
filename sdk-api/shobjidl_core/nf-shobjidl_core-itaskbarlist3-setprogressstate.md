# ITaskbarList3::SetProgressState

## Description

Sets the type and state of the progress indicator displayed on a taskbar button.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window in which the progress of an operation is being shown. This window's associated taskbar button will display the progress bar.

### `tbpFlags` [in]

Type: **TBPFLAG**

Flags that control the current state of the progress button. Specify only one of the following flags; all states are mutually exclusive of all others.

#### TBPF_NOPROGRESS (0x00000000)

Stops displaying progress and returns the button to its normal state. Call this method with this flag to dismiss the progress bar when the operation is complete or canceled.

#### TBPF_INDETERMINATE (0x00000001)

The progress indicator does not grow in size, but cycles repeatedly along the length of the taskbar button. This indicates activity without specifying what proportion of the progress is complete. Progress is taking place, but there is no prediction as to how long the operation will take.

#### TBPF_NORMAL (0x00000002)

The progress indicator grows in size from left to right in proportion to the estimated amount of the operation completed. This is a determinate progress indicator; a prediction is being made as to the duration of the operation.

#### TBPF_ERROR (0x00000004)

The progress indicator turns red to show that an error has occurred in one of the windows that is broadcasting progress. This is a determinate state. If the progress indicator is in the indeterminate state, it switches to a red determinate display of a generic percentage not indicative of actual progress.

#### TBPF_PAUSED (0x00000008)

The progress indicator turns yellow to show that progress is currently stopped in one of the windows but can be resumed by the user. No error condition exists and nothing is preventing the progress from continuing. This is a determinate state. If the progress indicator is in the indeterminate state, it switches to a yellow determinate display of a generic percentage not indicative of actual progress.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Progress bar information is not shown in high contrast color schemes to guarantee that no accessibility needs are compromised.

Developers accustomed to the existing [progress bar](https://learn.microsoft.com/windows/desktop/Controls/progress-bar-control-reference) control should find the taskbar button progress indicator to be a similar experience both in concept and visuals. Here, the taskbar button itself becomes a progress bar. A taskbar button's progress indicator should be a reflection of a more detailed progress bar in the associated window. This allows the user to see specifics, such as the percentage number and the amount of time remaining, that cannot be shown in a taskbar button. Also, because a taskbar button can show the progress of only a single window in a group, it allows the user to check the progress of individual windows. It also provides progress information to the user when the taskbar button cannot, such as in a high-contrast color scheme.

Note that a taskbar button progress bar is not intended for use with normally peripheral actions such as the loading of a webpage or the printing of a document. That type of progress should continue to be shown in a window's [status bar](https://learn.microsoft.com/windows/desktop/Controls/status-bar-reference).

The progress indicator is displayed between the taskbar button's icon or text and the background. If progress is shown for both the active taskbar button and an inactive button, shading in the respective progress bars is such that the active button is still obvious to the user. Also, button functionality such as the display of thumbnails continues to work normally when the button is being used to display progress.

When exiting an error or paused state, call this method again with the **TBPF_NORMAL** or **TBPF_INDETERMINATE** flag to continue in the original state or **TBPF_NOPROGRESS** if the operation is canceled.

### How the Taskbar Button Chooses the Progress Indicator for a Group

The taskbar button can show a progress indicator for only one window at a time. This includes the situation where the taskbar button represents a group and more than one window in that group is broadcasting progress information. In that case, the taskbar button chooses its progress display based on state priority. State priority is shown in the following table with priority 1 being the highest.

| Priority | State |
| --- | --- |
| 1 | TBPF_ERROR |
| 2 | TBPF_PAUSED |
| 3 | TBPF_NORMAL |
| 4 | TBPF_INDETERMINATE |

Changing a window's state changes its priority in relation to other windows in the group which in turn might change which window in a group is used for the progress indicator in the taskbar button.

In the case of a priority collision between two windows that are broadcasting determinate progress, the window with the least progress is used.

Based on this priority, the indeterminate progress indicator can be displayed in the taskbar button only in these cases:

* The taskbar button does not represent a group and the single window that it represents has set TBPF_INDETERMINATE.
* The taskbar button represents a group, only one window in that group is broadcasting progress information, and that window has set **TBPF_INDETERMINATE**.
* The taskbar button represents a group, multiple windows in that group are broadcasting progress information, and all of those windows have set **TBPF_INDETERMINATE**.

A determinate progress indicator can be displayed in these cases:

* The taskbar button does not represent a group and the single window that it represents is broadcasting determinate progress information.
* The taskbar button represents a group, only one window in that group is broadcasting progress information, and that window is broadcasting determinate progress information.
* The taskbar button represents a group, multiple windows in that group are broadcasting progress information, at least one of those windows is broadcasting determinate progress information, and no window has set **TBPF_ERROR** or **TBPF_PAUSED**.

Note that a call to [SetProgressValue](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-setprogressvalue) will switch a progress indicator currently in an indeterminate mode (**TBPF_INDETERMINATE**) to a normal (determinate) display and clear the **TBPF_INDETERMINATE** flag.

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[ITaskbarList3::SetProgressValue](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-setprogressvalue)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)