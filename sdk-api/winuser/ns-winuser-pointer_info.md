# POINTER_INFO structure

## Description

Contains basic pointer information common to all pointer types. Applications can retrieve this information using the [GetPointerInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfo), [GetPointerFrameInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfo), [GetPointerInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfohistory) and [GetPointerFrameInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerframeinfohistory) functions.

## Members

### `pointerType`

Type: **[POINTER_INPUT_TYPE](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)**

A value from the [POINTER_INPUT_TYPE](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type) enumeration that specifies the pointer type.

### `pointerId`

Type: **UINT32**

An identifier that uniquely identifies a pointer during its lifetime. A pointer comes into existence when it is first detected and ends its existence when it goes out of detection range. Note that if a physical entity (finger or pen) goes out of detection range and then returns to be detected again, it is treated as a new pointer and may be assigned a new pointer identifier.

### `frameId`

Type: **UINT32**

An identifier common to multiple pointers for which the source device reported an update in a single input frame. For example, a parallel-mode multi-touch digitizer may report the positions of multiple touch contacts in a single update to the system.

Note that frame identifier is assigned as input is reported to the system for all pointers across all devices. Therefore, this field may not contain strictly sequential values in a single series of messages that a window receives. However, this field will contain the same numerical value for all input updates that were reported in the same input frame by a single device.

### `pointerFlags`

Type: **[POINTER_FLAGS](https://learn.microsoft.com/windows/win32/inputmsg/pointer-flags-contants)**

May be any reasonable combination of flags from the [Pointer Flags](https://learn.microsoft.com/windows/win32/inputmsg/pointer-flags-contants) constants.

### `sourceDevice`

Type: **HANDLE**

Handle to the source device that can be used in calls to the raw input device API and the digitizer device API.

### `hwndTarget`

Type: **HWND**

Window to which this message was targeted. If the pointer is captured, either implicitly by virtue of having made contact over this window or explicitly using the pointer capture API, this is the capture window. If the pointer is uncaptured, this is the window over which the pointer was when this message was generated.

### `ptPixelLocation`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The predicted screen coordinates of the pointer, in pixels.

The predicted value is based on the pointer position reported by the digitizer and the motion of the pointer. This correction can compensate for visual lag due to inherent delays in sensing and processing the pointer location on the digitizer. This is applicable to pointers of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type). For other pointer types, the predicted value will be the same as the non-predicted value (see **ptPixelLocationRaw**).

### `ptHimetricLocation`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The predicted screen coordinates of the pointer, in HIMETRIC units.

The predicted value is based on the pointer position reported by the digitizer and the motion of the pointer. This correction can compensate for visual lag due to inherent delays in sensing and processing the pointer location on the digitizer. This is applicable to pointers of type [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type). For other pointer types, the predicted value will be the same as the non-predicted value (see **ptHimetricLocationRaw**).

### `ptPixelLocationRaw`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The screen coordinates of the pointer, in pixels. For adjusted screen coordinates, see **ptPixelLocation**.

### `ptHimetricLocationRaw`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The screen coordinates of the pointer, in HIMETRIC units. For adjusted screen coordinates, see **ptHimetricLocation**.

### `dwTime`

Type: **DWORD**

0 or the time stamp of the message, based on the system tick count when the message was received.

The application can specify the input time stamp in either **dwTime** or **PerformanceCount**. The value cannot be more recent than the current tick count or **QueryPerformanceCount (QPC)** value of the injection thread. Once a frame is injected with a time stamp, all subsequent frames must include a timestamp until all contacts in the frame go to an [UP](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-pointer_button_change_type) state. The custom timestamp value must also be provided for the first element in the contacts array. The time stamp values after the first element are ignored. The custom timestamp value must increment in every injection frame.

When **PerformanceCount** is specified, the time stamp will be converted to the current time in .1 millisecond resolution upon actual injection. If a custom **PerformanceCount** resulted in the same .1 millisecond window from the previous injection, **ERROR_NOT_READY** is returned and injection will not occur. While injection will not be invalidated immediately by the error, the next successful injection must have a **PerformanceCount** value that is at least 0.1 millisecond from the previously successful injection. This is also true if **dwTime** is used.

If both **dwTime** and **PerformanceCount** are specified in [InjectTouchInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-injecttouchinput), ERROR_INVALID_PARAMETER is returned.

[InjectTouchInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-injecttouchinput) cannot switch between **dwTime** and **PerformanceCount** once injection has started.

If neither **dwTime** and **PerformanceCount** are specified, [InjectTouchInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-injecttouchinput) allocates the timestamp based on the timing of the call. If **InjectTouchInput** calls are repeatedly less than 0.1 millisecond apart, ERROR_NOT_READY might be returned. The error will not invalidate the input immediately, but the injection application needs to retry the same frame again for injection to succeed.

### `historyCount`

Type: **UINT32**

Count of inputs that were coalesced into this message. This count matches the total count of entries that can be returned by a call to [GetPointerInfoHistory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfohistory). If no coalescing occurred, this count is 1 for the single input represented by the message.

### `InputData`

### `dwKeyStates`

Type: **DWORD**

 Indicates which keyboard modifier keys were pressed at the time the input was generated. May be zero, or a combination of the following values from [Modifier Key State](https://learn.microsoft.com/windows/win32/inputmsg/modifier-key-states-constants).

POINTER_MOD_SHIFT – A SHIFT key was pressed.

POINTER_MOD_CTRL – A CTRL key was pressed.

Use [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate).

### `PerformanceCount`

Type: **UINT64**

The value of the high-resolution performance counter when the pointer message was received (high-precision, 64 bit alternative to **dwTime**). The value can be calibrated when the touch digitizer hardware supports the scan timestamp information in its input report.

### `ButtonChangeType`

Type: **POINTER_BUTTON_CHANGE_TYPE**

A value from the [POINTER_BUTTON_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-pointer_button_change_type) enumeration that specifies the change in button state between this input and the previous input.

### `inputData`

Type: **INT32**

 A value whose meaning depends on the nature of input.

When flags indicate **POINTER_FLAG_WHEEL**, this value indicates the distance the wheel is rotated, expressed in multiples or factors of WHEEL_DELTA. A positive value indicates that the wheel was rotated forward and a negative value indicates that the wheel was rotated backward.

When flags indicate **POINTER_FLAG_HWHEEL,** this value indicates the distance the wheel is rotated, expressed in multiples or factors of WHEEL_DELTA. A positive value indicates that the wheel was rotated to the right and a negative value indicates that the wheel was rotated to the left.

## See also

[Structures](https://learn.microsoft.com/windows/win32/inputmsg/structures)