## Description

The **IoRegisterPlugPlayNotification** routine registers a Plug and Play (PnP) notification callback routine to be called when a PnP event of the specified category occurs.

## Parameters

### `EventCategory` [in]

Specifies an enumeration value from [**IO_NOTIFICATION_EVENT_CATEGORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-io_notification_event_category) that indicates the category of PnP event for which the callback routine is being registered.

### `EventCategoryFlags` [in]

Flag bits that modify the registration operation. Possible values include:

#### PNPNOTIFY_DEVICE_INTERFACE_INCLUDE_EXISTING_INTERFACES

Only valid with an *EventCategory* of **EventCategoryDeviceInterfaceChange**. If set, the PnP manager calls the driver callback routine for each device interface instance that is currently registered and active and registers the callback routine for future arrivals or removals of device interface instances.

### `EventCategoryData` [in, optional]

A pointer to further information about the events for which *CallbackRoutine* is being registered. The information varies for different *EventCategory* values:

- When *EventCategory* is **EventCategoryDeviceInterfaceChange**, *EventCategoryData* must point to a GUID specifying a device interface class. *CallbackRoutine* will be called when an interface of that class is enabled or removed.

- When *EventCategory* is **EventCategoryHardwareProfileChange**, *EventCategoryData* must be **NULL**.

- When *EventCategory* is **EventCategoryTargetDeviceChange**, *EventCategoryData* must point to the file object for which PnP notification is requested.

### `DriverObject` [in]

A pointer to the caller's driver object.

To ensure that the driver remains loaded while it is registered for PnP notification, this call increments the reference count on *DriverObject*. The PnP manager decrements the reference count when this registration is removed.

For **EventCategoryTargetDeviceChange**, *DriverObject* must not be the driver object of the target device; rather, it should be the driver object of the driver that implements *CallbackRoutine*.

### `CallbackRoutine` [in]

A pointer to the PnP notification callback routine to be called when the specified PnP event occurs.

The function prototype for this callback routine is defined as follows:

```cpp
typedef NTSTATUS
  DRIVER_NOTIFICATION_CALLBACK_ROUTINE(
    _In_ PVOID NotificationStructure,
    _Inout_opt_ PVOID Context
    );
```

The callback routine's *NotificationStructure* is specific to the *EventCategory* value, as shown in the following table.

| Event category | Notification structure |
|---|---|
| **EventCategoryDeviceInterfaceChange** | [**DEVICE_INTERFACE_CHANGE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_interface_change_notification) |
| **EventCategoryHardwareProfileChange** | [**HWPROFILE_CHANGE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_hwprofile_change_notification) |
| **EventCategoryTargetDeviceChange** | [**TARGET_DEVICE_REMOVAL_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_removal_notification)<br><br>For more information, see [Using PnP Notification](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-pnp-custom-notification) and [**TARGET_DEVICE_CUSTOM_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification). |

The callback routine's *Context* parameter contains the context data the driver supplied during registration.

For information about including a function declaration for the callback routine that meets the requirements of [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), see Examples.

The PnP manager calls driver callback routines at IRQL = PASSIVE_LEVEL.

### `Context` [in, optional]

A pointer to a caller-allocated buffer containing context that the PnP manager passes to the callback routine.

### `NotificationEntry` [out]

A pointer to an opaque value returned by this call that identifies the registration. Pass this value to the [IoUnregisterPlugPlayNotificationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregisterplugplaynotificationex) routine to remove the registration.

## Return value

**IoRegisterPlugPlayNotification** returns STATUS_SUCCESS or an appropriate error status.

## Remarks

A driver registers for an event category. Each category includes one or more types of PnP events.

A driver can register different callback routines for different event categories or can register a single callback routine. A single callback routine can cast the *NotificationStructure* to a [**PLUGPLAY_NOTIFICATION_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_plugplay_notification_header) and use the **Event** field to determine the exact type of the notification structure.

If the caller specifies PNPNOTIFY_DEVICE_INTERFACE_INCLUDE_EXISTING_INTERFACES, the operating system might call the PnP notification callback routine twice for a single **EventCategoryDeviceInterfaceChange** event for an existing interface. You can safely ignore the second call to the callback. The operating system will not call the callback more than twice for a single event.

PnP notification callback routines should complete their tasks as quickly as possible and return control to the PnP manager, to prevent delays in notifying other drivers and applications that have registered for the event.

The PnP manager does not take out a reference on the file object when a driver registers for notification of an **EventCategoryTargetDeviceChange** event. If the driver's PnP notification callback routine requires access to the file object, the driver should take out an extra reference on the file object before calling **IoRegisterPlugPlayNotification**.

Typically, Kernel-Mode Driver Framework (KMDF) drivers should call **IoRegisterPlugPlayNotification** from their [EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init) callback function, and should call **IoUnregisterPlugPlayNotification** from their [EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup) callback function. These drivers should **not** call **IoRegisterPlugPlayNotification** from their [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function; otherwise, the PnP notification callback routine might be called before the driver stack is started by PnP, in which case the driver will not be prepared to handle the notification.

For more information, see [Using PnP Notification](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-pnp-notification).

### Examples

To define a PnP notification callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a PnP notification callback routine that is named `MyCallbackRoutine`, use the DRIVER_NOTIFICATION_CALLBACK_ROUTINE type as shown in this code example:

```cpp
DRIVER_NOTIFICATION_CALLBACK_ROUTINE MyCallbackRoutine;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyCallbackRoutine(
    PVOID NotificationStructure,
    PVOID Context
    )
  {
      // Function body
  }
```

The **DRIVER_NOTIFICATION_CALLBACK_ROUTINE** function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the *Use_decl_annotations* annotation to your function definition. The *Use_decl_annotations* annotation ensures that the annotations that are applied to the DRIVER_NOTIFICATION_CALLBACK_ROUTINE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[Using PnP Notification](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-pnp-custom-notification)

[**DEVICE_INTERFACE_CHANGE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_interface_change_notification)

[EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup)

[EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init)

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[**HWPROFILE_CHANGE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_hwprofile_change_notification)

[IoUnregisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregisterplugplaynotification)

[IoUnregisterPlugPlayNotificationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregisterplugplaynotificationex)

[**PLUGPLAY_NOTIFICATION_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_plugplay_notification_header)

[**TARGET_DEVICE_CUSTOM_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification)

[**TARGET_DEVICE_REMOVAL_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_removal_notification)