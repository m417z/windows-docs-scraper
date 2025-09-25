# _IO_SESSION_STATE_NOTIFICATION structure

## Description

The **IO_SESSION_STATE_NOTIFICATION** structure contains information that a kernel-mode driver supplies to the [IoRegisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistercontainernotification) routine when the driver registers to receive notifications of session events.

## Members

### `Size`

The size, in bytes, of the **IO_SESSION_STATE_NOTIFICATION** structure.

### `Flags`

No flags are currently defined for this member. Set to zero.

### `IoObject`

A pointer to an I/O object owned by the driver. This member can point to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object), [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object), or [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure. The I/O object must remain valid for the lifetime of the registration. Before you delete a registered device object, unload a registered driver, or close a registered file object, call the [IoUnregisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregistercontainernotification) routine to cancel the registration. A driver can maintain simultaneous registrations for more than one I/O object, but it cannot create more than one active registration for the same I/O object.

### `EventMask`

Mask bits for session events. These mask bits indicate the events for which the driver requests notifications.

To register to receive notifications of session events, a kernel-mode driver calls the [IoRegisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistercontainernotification) routine. To specify the session events for which the driver wants to receive notifications, the driver sets this structure's **EventMask** member to the bitwise OR of one or more **IO_SESSION_STATE_*XXX*** constants.

Set this member to the bitwise OR of one or more of the following **IO_SESSION_STATE_*XXX*** constants:

| Value | Meaning |
| --- | --- |
| **IO_SESSION_STATE_ALL_EVENTS**<br><br>0xffffffff | Send notifications of all session events. |
| **IO_SESSION_STATE_CREATION_EVENT**<br><br>0x00000001 | Send a notification when the user session is created. |
| **IO_SESSION_STATE_TERMINATION_EVENT**<br><br>0x00000002 | Send a notification when the user session ends. |
| **IO_SESSION_STATE_CONNECT_EVENT**<br><br>0x00000004 | Send a notification when the user session is connected. |
| **IO_SESSION_STATE_DISCONNECT_EVENT**<br><br>0x00000008 | Send a notification when the user session is disconnected. |
| **IO_SESSION_STATE_LOGON_EVENT**<br><br>0x00000010 | Send a notification when the user logs on to the session. |
| **IO_SESSION_STATE_LOGOFF_EVENT**<br><br>0x00000020 | Send a notification when the user logs off of the session. |
| **IO_SESSION_STATE_VALID_EVENT_MASK**<br><br>0x0000003f | Send a notification when any type of session event occurs. |

### `Context`

A pointer to a context buffer in which the driver can store its private data for a particular session notification registration. The I/O manager passes this pointer to the driver's notification callback routine (specified by the **IoRegisterContainerNotification** routine's *CallbackFunction* parameter). The I/O manager does not try to validate the *Context* pointer or to access the buffer that it points to. This member can be **NULL** if the driver does not require a context buffer.

## Remarks

This structure is used by the **IoRegisterContainerNotification** routine. A driver that calls **IoRegisterContainerNotification** uses this structure to specify the session event notifications that it is registering for.

A per-session device object represents a device that can be accessed only by a particular user session. If a driver sets the **IoObject** member to point to a device object that is a per-session device object, **IoRegisterContainerNotification** registers the driver to receive only notifications of events that occur in the session that is represented by the device object. If **IoObject** points to a device object that is not a per-session device object, or if **IoObject** points to an object that is not a device object, **IoRegisterContainerNotification** registers the driver to receive notifications of events that occur in all sessions on the computer.

To determine whether a device object is a per-session device object, a driver can call the [IoGetDevicePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdevicepropertydata) routine to query the [DEVPKEY_Device_SessionId](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-sessionid) property key in the property store of the device object. If the **DEVPKEY_Device_SessionId** property exists and the value of the property is set to a nonzero [Terminal Services](https://learn.microsoft.com/windows/win32/termserv/terminal-services-portal) session identifier, the device object is a per-session device object. For more information, see [DEVPKEY_Device_SessionId](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-sessionid).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DEVPKEY_Device_SessionId](https://learn.microsoft.com/windows-hardware/drivers/install/devpkey-device-sessionid)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[IoGetDevicePropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdevicepropertydata)

[IoRegisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistercontainernotification)