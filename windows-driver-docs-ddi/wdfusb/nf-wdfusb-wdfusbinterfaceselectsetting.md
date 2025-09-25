# WdfUsbInterfaceSelectSetting function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbInterfaceSelectSetting** method selects a specified alternate setting for a specified USB interface.

## Parameters

### `UsbInterface` [in]

A handle to a USB interface object that was obtained by calling [WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface).

### `PipesAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for pipe objects that the framework creates for the interface. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Params` [in]

A pointer to a caller-supplied [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure that contains interface selection parameters.

## Return value

**WdfUsbInterfaceSelectSetting** returns the I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to create a new pipe object. |

For a list of other return values that the **WdfUsbInterfaceSelectSetting** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

After your driver calls [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig) to select a configuration, the driver can call **WdfUsbInterfaceSelectSetting** to select an alternate setting for one of the device's interfaces.

Your driver can select an interface's alternate setting by specifying a USB interface descriptor or a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb), or by just providing an alternate setting for the interface. In all cases, the driver must provide a handle to an interface object.

If your driver just provides an alternate setting, the framework uses the interface object to determine the interface to which the setting belongs.

If your driver specifies an interface descriptor or a URB, the framework uses the interface that is specified in the descriptor or URB.

The framework creates a framework USB pipe object for each pipe that is associated with the interface, after deleting any pipe objects that the framework might have previously created for the interface. To obtain information about an interface's pipe objects, your driver can call [WdfUsbInterfaceGetNumConfiguredPipes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetnumconfiguredpipes) and [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

For more information about the **WdfUsbInterfaceSelectSetting** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure with attributes for the pipe objects that the framework will create. Then, the example initializes a [WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params) structure to specify alternate setting 1. Finally, the example calls **WdfUsbInterfaceSelectSetting** to select the alternate setting and create pipe objects for the interface's pipes.

```cpp
WDF_OBJECT_ATTRIBUTES  pipesAttributes;
WDF_USB_INTERFACE_SELECT_SETTING_PARAMS  selectSettingParams;
NTSTATUS  Status;

WDF_OBJECT_ATTRIBUTES_INIT(&pipesAttributes);
WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE(
                                       &pipesAttributes,
                                       MY_PIPE_CONTEXT
                                       );

WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING(
                                      &selectSettingParams,
                                      1
                                      );

Status = WdfUsbInterfaceSelectSetting(
                                      UsbInterface,
                                      &pipesAttributes,
                                      &selectSettingParams
                                      );
```

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-set-context-type)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_interface_select_setting_params)

[WDF_USB_INTERFACE_SELECT_SETTING_PARAMS_INIT_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_interface_select_setting_params_init_setting)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)

[WdfUsbInterfaceGetNumConfiguredPipes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetnumconfiguredpipes)

[WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface)

[WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig)