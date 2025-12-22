# WdfDeviceOpenRegistryKey function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceOpenRegistryKey** method opens a device's hardware key or a driver's software key in the registry and creates a framework registry-key object that represents the registry key.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceInstanceKeyType` [in]

Specifies which key or subkey to open.

> [!NOTE]
> UMDF does not support creating subkeys.

This is a bitwise OR of the following flags (which are defined in *Wdm.h*).

| DeviceInstanceKeyType flag | Meaning | Framework |
| --- | --- | --- |
| **PLUGPLAY_REGKEY_DEVICE** | Opens the device's hardware key. | KMDF/UMDF |
| **PLUGPLAY_REGKEY_DRIVER** | Opens the driver's software key. A UMDF driver that sets this flag must also set *DesiredAccess* to **KEY_READ**. Otherwise this method returns **STATUS_ACCESS_DENIED**. | KMDF/UMDF |
| **PLUGPLAY_REGKEY_CURRENT_HWPROFILE** | A KMDF driver uses this flag to open the copy of the hardware or software key that is in the current hardware profile. | KMDF |
| **PLUGPLAY_REGKEY_DRIVER \| WDF_REGKEY_DRIVER_SUBKEY** | A UMDF driver uses these flags together to open the **ServiceName** subkey of the driver's software key for read/write access. | UMDF |
| **PLUGPLAY_REGKEY_DEVICE \| WDF_REGKEY_DEVICE_SUBKEY** | Similarly, a UMDF driver uses these flags to open the **ServiceName** subkey of the device's hardware key for read/write access. | UMDF |

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)-typed value that specifies access rights that the driver is requesting for the specified registry key.

A KMDF driver typically requests **KEY_READ**, **KEY_WRITE**, or **KEY_READ | KEY_WRITE**.

If you are writing a UMDF driver, use the following table.

| DeviceInstanceKeyType | DesiredAccess |
| --- | --- |
| **PLUGPLAY_REGKEY_DEVICE** | **KEY_READ** |
| **PLUGPLAY_REGKEY_DEVICE \| WDF_REGKEY_DEVICE_SUBKEY** | **KEY_READ** or **KEY_READ \| KEY_SET_VALUE** |
| **PLUGPLAY_REGKEY_DRIVER** | **KEY_READ** |
| **PLUGPLAY_REGKEY_DRIVER \| WDF_REGKEY_DRIVER_SUBKEY** | **KEY_READ** or **KEY_READ \| KEY_SET_VALUE** |

As a best practice, ask for only the types of access that your driver needs.

### `KeyAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new registry-key object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Key` [out]

A pointer to a location that receives a handle to the new registry-key object.

## Return value

**WdfDeviceOpenRegistryKey** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfDeviceOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceopenregistrykey) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. For UMDF, this return value can indicate insufficient access rights. |
| **STATUS_INSUFFICIENT_RESOURCES** | A registry-key object could not be allocated. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The specified registry key does not exist. |

For a list of other return values that the **WdfDeviceOpenRegistryKey** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If your driver must open a hardware or software key before it has called [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), it must call [WdfFdoInitOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitopenregistrykey) instead of **WdfDeviceOpenRegistryKey**.

When the driver has finished using the registry key that it opened with **WdfDeviceOpenRegistryKey**, the driver must call [WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose).

For more information about the registry, hardware and software keys, and registry objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

For code examples that use **WdfDeviceOpenRegistryKey**, see [WdfRegistryCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistrycreatekey), [WdfRegistryOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryopenkey), and [WdfRegistryQueryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryvalue).

## See also

[WdfFdoInitOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitopenregistrykey)