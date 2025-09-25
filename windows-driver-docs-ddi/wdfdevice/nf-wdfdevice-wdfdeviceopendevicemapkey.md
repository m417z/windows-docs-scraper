# WdfDeviceOpenDevicemapKey function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceOpenDevicemapKey** method opens the **DEVICEMAP** key and creates a framework registry-key object that represents the registry key.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `KeyName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that specifies the name of the subkey to open under **DEVICEMAP**.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)-typed value that specifies access rights that the driver is requesting for the specified registry key.

A KMDF driver typically requests **KEY_READ**, **KEY_WRITE**, or **KEY_READ | KEY_WRITE**.

A UMDF driver typically requests **KEY_READ** or **KEY_SET_VALUE**.

### `KeyAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new registry-key object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Key` [out]

A pointer to a location that receives a handle to the new registry-key object. The

## Return value

**WdfDeviceOpenDevicemapKey** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfDeviceOpenDevicemapKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceopendevicemapkey) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. For UMDF, this return value can indicate insufficient access rights. |
| **STATUS_INSUFFICIENT_RESOURCES** | A registry-key object could not be allocated. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The specified registry key does not exist. |

For a list of other return values that the **WdfDeviceOpenDevicemapKey** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The registry contains a **HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP** key that some drivers for older technologies, such as serial and parallel ports, use. If your driver supports a technology that uses the **DEVICEMAP** key, the driver can access subkeys and values under the key by calling **WdfDeviceOpenDevicemapKey**.

**WdfDeviceOpenDevicemapKey** returns a volatile *Key*. This means that the information is not preserved when the corresponding registry hive is unloaded.

When the driver has finished using the registry key that it opened with **WdfDeviceOpenDevicemapKey**, the driver must call [WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose).

For more information about the registry, hardware and software keys, and registry objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

## See also

[WdfDeviceOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceopenregistrykey)

[WdfFdoInitOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitopenregistrykey)