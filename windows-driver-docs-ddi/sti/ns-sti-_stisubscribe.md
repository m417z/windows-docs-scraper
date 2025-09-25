# _STISUBSCRIBE structure

## Description

The STISUBSCRIBE structure is used as a parameter for the [IStiDevice::Subscribe](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-subscribe) method.

## Members

### `dwSize`

Caller-supplied size, in bytes, of the STISUBSCRIBE structure.

### `dwFlags`

One of the following bit flags, defined in *sti.h*.

#### STI_SUBSCRIBE_FLAG_EVENT

Event notifications should be delivered to the application by calls to **SetEvent**. The **hEvent** member contains a Win32 event handle.

This bit flag is preferred for security reasons.

#### STI_SUBSCRIBE_FLAG_WINDOW

Event notifications should be delivered to the application using window messages. The **dwWndNotify** member contains a window handle and **uiNotificationMessage** contains a window message.

This bit flag is obsolete. Do not use.

### `dwFilter`

Reserved for system use.

### `hWndNotify`

Handle to an application window that should receive the message specified by **uiNotificationMessage** when an event occurs. Used only if STI_SUBSCRIBE_FLAG_WINDOW is set in **dwFlags**.

### `hEvent`

Handle to a Win32 event created with **CreateEvent**, which the event monitor will use with **SetEvent** when an event occurs and for which the application can wait. Used only if STI_SUBSCRIBE_FLAG_WINDOW is set in **dwFlags**.

### `uiNotificationMessage`

Window message that should be passed to the **dwWndNotify** window when an event occurs.