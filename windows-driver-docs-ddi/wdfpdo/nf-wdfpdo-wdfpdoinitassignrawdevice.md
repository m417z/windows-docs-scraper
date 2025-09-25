# WdfPdoInitAssignRawDevice function

## Description

[Applies to KMDF only]

The **WdfPdoInitAssignRawDevice** method indicates that the calling driver can support a specified device in raw mode.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `DeviceClassGuid` [in]

A pointer to a GUID that identifies a [device setup class](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_devinfo_data).

**Note** You should always specify a custom class GUID. You should not specify an existing class GUID. If you specify an existing class GUID, other drivers that attempt to specify that existing class GUID might fail to install or might install with incorrect security settings.

For more information, see the following Remarks section.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Otherwise it returns STATUS_INVALID_PARAMETER.

## Remarks

The driver must call **WdfPdoInitAssignRawDevice** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

The registry can contain values that override the values that a driver specifies when it calls [WdfDeviceInitAssignSDDLString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignsddlstring), [WdfDeviceInitSetDeviceType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetdevicetype), [WdfDeviceInitSetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetcharacteristics), and [WdfDeviceInitSetExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetexclusive). The **WdfPdoInitAssignRawDevice** method's *DeviceClassGuid* parameter specifies a GUID that identifies the section of the registry that contains the override values. The *DeviceClassGuid* parameter only identifies a section of the registry and does not actually set the [device setup class](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_devinfo_data) for the device. The [INF Version section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-version-section) in your device and driver's INF file sets the device setup class. Typically, the *DeviceClassGuid* parameter's GUID should match the GUID that the **INF Version section** specifies.

For more information about using the registry, see [Setting Device Object Registry Properties After Installation](https://learn.microsoft.com/windows-hardware/drivers/kernel/setting-device-object-registry-properties-after-installation).

#### Examples

The following snippet from the kmdf_enumswitches driver sample indicates that a driver can support the specified device in raw mode.

```cpp
NTSTATUS  status;
DEFINE_GUID(GUID_DEVCLASS_MYUNIQUEID,
0xf149fe88, 0x f6cc, 0x47e3, 0x85, 0x94, 0xe2, 0xaa, 0xb6, 0xe0, 0x3b, 0xdf);

status = WdfPdoInitAssignRawDevice(
                                   pDeviceInit,
                                   &GUID_DEVCLASS_MYUNIQUEID
                                   );

```

## See also

[WdfDeviceInitAssignSDDLString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignsddlstring)

[WdfDeviceInitSetCharacteristics](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetcharacteristics)

[WdfDeviceInitSetDeviceType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetdevicetype)

[WdfDeviceInitSetExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetexclusive)