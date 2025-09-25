# WdfDeviceInitSetDeviceClass function

## Description

[Applies to KMDF only]

The **WdfDeviceInitSetDeviceClass** method specifies a GUID that identifies the device's [device setup class](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_devinfo_data).

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `DeviceClassGuid` [in]

Pointer to a GUID that identifies a section of the registry containing possible overrides for the *DefaultSDDLString*, *DeviceType*, *DeviceCharacteristics*, and *Exclusive* parameters.

**Note** You should always specify a custom class GUID. You should not specify an existing class GUID. If you specify an existing class GUID, other drivers that attempt to specify that existing class GUID might fail to install or might install with incorrect security settings.

## Remarks

The registry can contain values that override the values that a driver specifies when it calls [WdfDeviceInitAssignSDDLString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignsddlstring), [WdfDeviceInitSetDeviceType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetdevicetype), [WdfDeviceInitSetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetcharacteristics), and [WdfDeviceInitSetExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetexclusive). The driver can call **WdfDeviceInitSetDeviceClass** to specify a GUID that identifies the section of the registry that contains the override values.

Typically, a driver calls **WdfDeviceInitSetDeviceClass** only if it is creating a [control device](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects).

For more information about using the registry, see [Setting Device Object Registry Properties After Installation](https://learn.microsoft.com/windows-hardware/drivers/kernel/setting-device-object-registry-properties-after-installation).

If a driver calls **WdfDeviceInitSetDeviceClass**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example sets a device's setup class to the system device class.

```cpp
DEFINE_GUID(GUID_DEVCLASS_MYUNIQUEID,
0xf149fe88, 0x f6cc, 0x47e3, 0x85, 0x94, 0xe2, 0xaa, 0xb6, 0xe0, 0x3b, 0xdf);

WdfDeviceInitSetDeviceClass(
                            DeviceInit,
                            &GUID_DEVCLASS_MYUNIQUEID
                            );

```