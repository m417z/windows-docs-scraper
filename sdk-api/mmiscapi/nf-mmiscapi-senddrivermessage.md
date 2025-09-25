# SendDriverMessage function

## Description

Sends the specified message to the installable driver.

## Parameters

### `hDriver` [in]

Handle of the installable driver instance. The handle must been previously created by using the [OpenDriver](https://learn.microsoft.com/previous-versions/dd743639(v=vs.85)) function.

### `message` [in]

Driver message value. It can be a custom message value or one of these standard message values.

| Value | Meaning |
| --- | --- |
| **[DRV_QUERYCONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-queryconfigure)** | Queries an installable driver about whether it supports the **DRV_CONFIGURE** message and can display a configuration dialog box. |
| **[DRV_CONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-configure)** | Notifies an installable driver that it should display a configuration dialog box. (This message should only be sent if the driver returns a nonzero value when the [DRV_QUERYCONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-queryconfigure) message is processed.) |
| **[DRV_INSTALL](https://learn.microsoft.com/windows/desktop/Multimedia/drv-install)** | Notifies an installable driver that it has been successfully installed. |
| **[DRV_REMOVE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-remove)** | Notifies an installable driver that it is about to be removed from the system. |

### `lParam1` [in, out]

32-bit message-dependent information.

### `lParam2` [in, out]

32-bit message-dependent information.

## Return value

Returns nonzero if successful or zero otherwise.

## See also

[Installable Driver Functions](https://learn.microsoft.com/windows/desktop/Multimedia/installable-driver-functions)

[Installable Drivers](https://learn.microsoft.com/windows/desktop/Multimedia/installable-drivers)