# PSERVICE_CALLBACK_ROUTINE callback function

## Description

A function driver calls the class service callback in its ISR dispatch completion routine. The class service callback transfers input data from the input data buffer of a device to the class data queue.

## Parameters

### `NormalContext` [in]

Pointer to the class device object.

### `SystemArgument1` [in]

Pointer to the first keyboard input data packet in the input data buffer of the port device.

### `SystemArgument2` [in]

Pointer to the keyboard input data packet that immediately follows the last data packet in the input data buffer of the port device.

### `SystemArgument3` [in, out]

Pointer to the number of keyboard input data packets that are transferred by the routine.

## Remarks

**Keyboard Class Service Callback**

Here is the definition of the keyboard class service callback routine.

Kbdclass uses an [IOCTL_INTERNAL_KEYBOARD_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ni-kbdmou-ioctl_internal_keyboard_connect) request to connect its class service callback to a keyboard device. In this call, the driver sets its implementation in a [CONNECT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ns-kbdmou-_connect_data) structure.

```
/*
DeviceObject [in]
Pointer to the class device object.

InputDataStart [in]
Pointer to the first keyboard input data packet in the input data buffer of the port device.

InputDataEnd [in]
Pointer to the keyboard input data packet that immediately follows the last data packet in the input data buffer of the port device.

InputDataConsumed [in, out]
Pointer to the number of keyboard input data packets that are transferred by the routine.

*/
VOID KeyboardClassServiceCallback(
  _In_    PDEVICE_OBJECT       DeviceObject,
  _In_    PKEYBOARD_INPUT_DATA InputDataStart,
  _In_    PKEYBOARD_INPUT_DATA InputDataEnd,
  _Inout_ PULONG               InputDataConsumed
);
```

**KeyboardClassServiceCallback** transfers input data from the input buffer of the device to the class data queue. This routine is called by the ISR dispatch completion routine of the function driver.

**KeyboardClassServiceCallback** can be supplemented by a filter service callback that is provided by an upper-level keyboard filter driver. A filter service callback filters the keyboard data that is transferred to the class data queue. For example, the filter service callback can delete, transform, or insert data. [Kbfiltr](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples), the sample filter driver in code gallery, includes **KbFilter_ServiceCallback**, which is a template for a keyboard filter service callback.

**Mouse Class Service Callback**

Here is the **MouseClassServiceCallback** routine is the class service callback routine that is provided by Mouclass. The driver uses an [IOCTL_INTERNAL_MOUSE_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ni-kbdmou-ioctl_internal_mouse_connect) request to connect its class service callback to a mouse device. In this call, the driver sets its implementation in a [CONNECT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ns-kbdmou-_connect_data) structure.

```
/*
DeviceObject [in]
Pointer to the class device object.

InputDataStart [in]
Pointer to the first mouse input data packet in the input buffer of the port device.

InputDataEnd [in]
Pointer to the mouse input data packet that immediately follows the last data packet in the input data buffer of the port device.

InputDataConsumed [in, out]
Pointer to the number of mouse input data packets that are transferred by the routine.

*/
VOID MouseClassServiceCallback(
  _In_    PDEVICE_OBJECT    DeviceObject,
  _In_    PMOUSE_INPUT_DATA InputDataStart,
  _In_    PMOUSE_INPUT_DATA InputDataEnd,
  _Inout_ PULONG            InputDataConsumed
);
);
```

**MouseClassServiceCallback** transfers input data from the input buffer of the device to the class data queue. This routine is called by the ISR dispatch completion routine of the function driver.

**MouseClassServiceCallback** can be supplemented by a filter service callback that is provided by an upper-level mouse filter driver. A filter service callback can filter the mouse data that is transferred to the class data queue. For example, the filter service callback can delete, transform, or insert data. [Moufiltr](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples), the sample filter driver in the WDK, includes **MouFilter_ServiceCallback**, which is a template for a filter service callback.

## See also

[CONNECT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/kbdmou/ns-kbdmou-_connect_data)

[KEYBOARD_INPUT_DATA](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_input_data)

[MOUSE_INPUT_DATA](https://learn.microsoft.com/windows/win32/api/ntddmou/ns-ntddmou-mouse_input_data)