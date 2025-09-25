# PcRegisterIoTimeout function

## Description

The **PcRegisterIoTimeout** function registers a driver-supplied I/O-timer callback routine for a specified device object.

Once registered, the port-class driver calls the timer callback approximately once per second for as long as the device remains active.

**Note** This function is deprecated for Windows 8 and later versions of Windows. For Windows on Arm systems, this function is commented out in the PortCls class driver and is inaccessible.

## Parameters

### `pDeviceObject` [in]

Pointer to a device object representing a device on which I/O operations can time out. This parameter must point to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object). When calling the I/O-timer callback routine, the port class driver passes this pointer as the first of two call parameters. For more information, see the following Remarks section.

### `pTimerRoutine` [in]

Pointer to the driver-supplied I/O-timer callback routine. For more information, see the following Remarks section.

### `pContext` [in]

Pointer to the driver-specific context. When calling the I/O-timer callback routine, the port class driver passes this pointer as the second of two call parameters. For more information, see the following Remarks section.

## Return value

**PcRegisterIoTimeout** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code. The following table shows some of the possible error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | Possibly indicates that a memory allocation failed inside the port-class driver. |
| **STATUS_UNSUCCESSFUL** | Possibly indicates that a timer callback with the same combination of device object, I/O-timer callback routine, and context is already registered. |

## Remarks

An adapter driver calls the **PcRegisterIoTimeout** function to enable a low-resolution watchdog timer. Drivers use this function primarily to monitor devices that have no means to generate an event themselves if they fail to complete a previously initiated I/O operation within some maximum time interval.

After the driver calls **PcRegisterIoTimeout**, the port-class driver calls the driver's I/O-timer callback routine approximately once per second for as long as the device remains active. (The device is activated by an IRP_MN_START_DEVICE request and deactivated by an IRP_MN_STOP_DEVICE request.)

The driver can disable the timer by calling [PcUnregisterIoTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcunregisteriotimeout).

Only one timer callback with a particular combination of device object, I/O-timer callback routine, and context can be registered at a time.

The meaning of the *pContext* parameter is determined by the adapter driver, but the driver typically sets this parameter to point to an object such as the miniport, miniport-stream, or adapter object.

The *pTimerRoutine* parameter is of type PIO_TIMER_ROUTINE, which is defined in ntddk.h to be

```
  VOID
    (*PIO_TIMER_ROUTINE)(
      IN PDEVICE_OBJECT  DeviceObject,
      IN PVOID  Context
      );
```

The *DeviceObject* and *Context* parameters are the same values that the adapter driver previously passed as call parameters to **PcRegisterIoTimeout**. The port-class driver calls the timer routine at IRQL DISPATCH_LEVEL. The timer routine must not contain pageable code.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[PcUnregisterIoTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcunregisteriotimeout)