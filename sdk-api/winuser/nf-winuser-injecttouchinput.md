# InjectTouchInput function

## Description

Simulates touch input.

**Note** [InitializeTouchInjection](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-initializetouchinjection) must precede any call to [InjectTouchInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-injecttouchinput).

## Parameters

### `count` [in]

The size of the array in *contacts*.

The maximum value for *count* is specified by the *maxCount* parameter of the [InitializeTouchInjection](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-initializetouchinjection) function.

### `contacts` [in]

Array of [POINTER_TOUCH_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_touch_info) structures that represents all contacts on the desktop. The screen coordinates of each contact must be within the bounds of the desktop.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The injected input is sent to the desktop of the session where the injection process is running.

There are two input states for touch input injection (interactive and hover) that are indicated by the following combinations of **pointerFlags** in *contacts*:

| **pointerFlags (POINTER_FLAG_*)** | Status |
| --- | --- |
| INRANGE | UPDATE | Touch hover starts or moves |
| INRANGE | INCONTACT | DOWN | Touch contact down |
| INRANGE | INCONTACT | UPDATE | Touch contact moves |
| INRANGE | UP | Touch contact up and transition to hover |
| UPDATE | Touch hover ends |
| UP | Touch ends |

**Note** Interactive state represents a touch contact that is on-screen and able to interact with any touch-capable app. Hover state represents touch input that is not in contact with the screen and cannot interact with applications. Touch injection can start in hover or interactive state, but the state can only transition through INRANGE | INCONTACT | DOWN for hover to interactive state, or through INRANGE | UP for interactive to hover state.

All touch injection sequences end with either UPDATE or UP.

The following diagram demonstrates a touch injection sequence that starts with a hover state, transitions to interactive, and concludes with hover.

:::image type="content" source="./images/inputstates.png" border="false" alt-text="Diagram of a touch injection sequence showing the state transitions from hover to interactive to hover.":::

For press and hold gestures, multiple frames must be sent to ensure input is not cancelled. For a press and hold at point (x,y), send [WM_POINTERDOWN](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdown) at point (x,y) followed by [WM_POINTERUPDATE](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerupdate) messages at point(x,y).

Listen for [WM_DISPLAYCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-displaychange) to handle changes to display resolution and orientation and manage screen coordinate updates. All active contacts are cancelled when a **WM_DISPLAYCHANGE** is received.

Cancel individual contacts by setting POINTER_FLAG_CANCELED with POINTER_FLAG_UP or POINTER_FLAG_UPDATE. Cancelling touch injection without POINTER_FLAG_UP or POINTER_FLAG_UPDATE invalidates the injection.

When POINTER_FLAG_UP is set, ptPixelLocation of [POINTER_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_info) should be the same as the value of the previous touch injection frame with POINTER_FLAG_UPDATE. Otherwise, the injection fails with ERROR_INVALID_PARAMETER and all active injection contacts are cancelled. The system modifies the ptPixelLocation of the [WM_POINTERUP](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerup) event as it cancels the injection.

The input timestamp can be specified in either the dwTime or PerformanceCount field of [POINTER_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_info). The value cannot be more recent than the current tick count or [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter) value of the injection thread. Once a frame is injected with a timestamp, all subsequent frames must include a timestamp until all contacts in the frame go to the UP state. The custom timestamp value must be provided for the first element in the contacts array. The timestamp values after the first element are ignored. The custom timestamp value must increment in every injection frame.

When a PerformanceCount field is specified, the timestamp is converted into current time in .1 millisecond resolution upon actual injection. If a custom PerformanceCount resulted in the same .1 millisecond window from previous injection, the API will return an error (ERROR_NOT_READY) and will not inject the data. While injection is not immediately invalidated by the error, next successful injection must have PerformanceCount value that is at least 0.1 milliseconds apart from the previously successful injection. Similarly a custom dwTime value must be at least 1 millisecond apart if the field was used.

If both dwTime and PerformanceCount are specified in the injection parameter, [InjectTouchInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-injecttouchinput) fails with an Error Code (ERROR_INVALID_PARAMETER). Once the injection application starts with either a dwTime or PerformanceCount parameter, the timestamp field must be filled correctly. Injection cannot switch the custom timestamp field from one to another once the injection sequence has started.

When neither dwTime or PerformanceCount values are specified, the [InjectTouchInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-injecttouchinput) allocates the timestamp based on the timing of the API call. If the calls are less than 0.1 millisecond apart, the API may return an error (ERROR_NOT_READY). The error will not invalidate the input immediately, but the injection application needs to retry the same frame again to ensure injection is successful.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/xinput/functions)