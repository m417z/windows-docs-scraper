# WdfWdmDeviceGetWdfDeviceHandle function

## Description

[Applies to KMDF only]

The **WdfWdmDeviceGetWdfDeviceHandle** method returns a handle to the framework device object that is associated with a specified WDM device object.

## Parameters

### `DeviceObject` [in]

A pointer to a WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that the calling driver created.

## Return value

If the specified WDM device object is valid, **WdfWdmDeviceGetWdfDeviceHandle** returns a handle to the associated framework device object. Otherwise, the method returns **NULL**.

## Remarks

The WDM DEVICE_OBJECT structure that the driver specifies for the *DeviceObject* parameter must represent a device object that the calling driver created. For example, the structure cannot represent any of the WDM device objects that the driver specified in a previous call to [WdfDeviceMiniportCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfminiport/nf-wdfminiport-wdfdeviceminiportcreate).

#### Examples

The following code example obtains a handle to the framework device object that is associated with a WDM device object that the calling driver created.

```cpp
WDFDEVICE  device;

device = WdfWdmDeviceGetWdfDeviceHandle(pWdmDeviceObject);
```

## See also

[WdfDeviceMiniportCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfminiport/nf-wdfminiport-wdfdeviceminiportcreate)