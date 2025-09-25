# WdfFdoInitWdmGetPhysicalDevice function

## Description

[Applies to KMDF only]

The **WdfFdoInitWdmGetPhysicalDevice** method retrieves a device's WDM physical device object (PDO).

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that the driver obtained from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

## Return value

If the operation succeeds, the method returns a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. Otherwise the method returns **NULL**.

## Remarks

The driver must call **WdfFdoInitWdmGetPhysicalDevice** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

For more information about the **WdfFdoInitWdmGetPhysicalDevice** method, see [Creating Device Objects in a Function Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-device-objects-in-a-function-driver).

#### Examples

The following code example obtains a pointer to a DEVICE_OBJECT structure that represents a device's WDM PDO.

```cpp
PDEVICE_OBJECT device;

device = WdfFdoInitWdmGetPhysicalDevice(DeviceInit);
```