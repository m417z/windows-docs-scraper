# UfxDevicePortDetectCompleteEx function

## Description

Notifies UFX about the port type that was detected, and optionally requests an action.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `PortType` [in]

Contains an enumeration value of type [USBFN_PORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_port_type).

### `Action` [in]

Contains an enumeration value of type [USBFN_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxbase/ne-ufxbase-_usbfn_action).

## Remarks

The client driver calls **UfxDevicePortDetectCompleteEx** after port detection is complete, typically from its [EVT_UFX_DEVICE_PORT_DETECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_port_detect) callback function. On some platforms, UFX may use the reported port type to notify the battery manager of the maximum current it can draw from the USB port.

If the *Action* parameter is set to **UsbfnActionNoCad**, UFX does not notify the battery manager at all.

If the *Action* parameter is set to **UsbfnActionDetectProprietaryCharger**, UFX requests that the client driver initiate proprietary charger detection by calling the client driver’s [EVT_UFX_DEVICE_DETECT_PROPRIETARY_CHARGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_proprietary_charger_detect) callback function.

The following snippet shows how a client driver calls **UfxDevicePortDetectCompleteEx**.

```
    switch (OnAttach.AttachAction) {
    case UsbfnPortDetected:
        TraceInformation("Port Detected");
        UfxDevicePortDetectComplete(
            ControllerData->UfxDevice,
            OnAttach.PortType);

        break;

    case UsbfnPortDetectedNoCad:
        TraceInformation("Port Detected No CAD");
        UfxDevicePortDetectCompleteEx(
            ControllerData->UfxDevice,
            OnAttach.PortType,
            UsbfnActionNoCad);

        break;

```