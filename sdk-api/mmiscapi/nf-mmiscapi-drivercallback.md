# DriverCallback function

## Description

Calls a callback function, sends a message to a window, or unblocks a thread. The action depends on the value of the notification flag. This function is intended to be used only within the [DriverProc](https://learn.microsoft.com/previous-versions/dd797918(v=vs.85)) function of an installable driver.

## Parameters

### `dwCallback`

Address of the callback function, a window handle, or a task handle, depending on the flag specified in the *dwFlags* parameter.

### `dwFlags`

Notification flags. It can be one of these values:

| Value | Meaning |
| --- | --- |
| **DCB_NOSWITCH** | The system is prevented from switching stacks. This value is only used if enough stack space for the callback function is known to exist. |
| **DCB_FUNCTION** | The *dwCallback* parameter is the address of an application-defined callback function. The system sends the callback message to the callback function. |
| **DCB_WINDOW** | The *dwCallback* parameter is the handle of an application-defined window. The system sends subsequent notifications to the window. |
| **DCB_TASK** | The *dwCallback* parameter is the handle of an application or task. The system sends subsequent notifications to the application or task. |

### `hDevice`

Handle of the installable driver instance.

### `dwMsg`

Message value.

### `dwUser`

32-bit user-instance data supplied by the application when the device was opened.

### `dwParam1`

32-bit message-dependent parameter.

### `dwParam2`

32-bit message-dependent parameter.

## Return value

Returns **TRUE** if successful or **FALSE** if a parameter is invalid or the task's message queue is full.

## Remarks

The client specifies how to notify it when the device is opened. The DCB_FUNCTION and DCB_WINDOW flags are equivalent to the high-order word of the corresponding flags CALLBACK_FUNCTION and CALLBACK_WINDOW specified in the *lParam2* parameter of the [DRV_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/drv-open) message when the device was opened.

If notification is accomplished with a callback function, *hdrvr*, *msg*, *dwUser*, *dwParam1*, and *dwParam2* are passed to the callback function. If notification is accomplished by means of a window, only *msg*, *hdrvr*, and *dwParam1* are passed to the window.

## See also

[Driver Functions](https://learn.microsoft.com/windows/desktop/Multimedia/driver-functions)

[Installable Drivers](https://learn.microsoft.com/windows/desktop/Multimedia/installable-drivers)