# WdfPdoInitAddHardwareID function

## Description

[Applies to KMDF only]

The **WdfPdoInitAddHardwareID** method adds a hardware ID to the list of hardware IDs for a child device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `HardwareID` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a hardware ID string. The driver can allocate the string's buffer from paged pool.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The driver is initializing an FDO instead of a PDO. |
| **STATUS_INSUFFICIENT_RESOURCES** | The driver could not allocate space to store the hardware ID string. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The driver can add one or more hardware IDs for a device. They should be added in order from best match to worst match. The framework will deliver the IDs to the PnP manager in the order that they were added. For more information about hardware IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings) and [How Setup Selects Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/how-setup-selects-drivers).

The driver must call **WdfPdoInitAddHardwareID** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example reports a hardware ID that the [KbFiltr](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver uses.

```cpp
#define  KBFILTR_DEVICE_ID L"{A65C87F9-BE02-4ed9-92EC-012D416169FA}\\KeyboardFilter\0"
DECLARE_CONST_UNICODE_STRING(hardwareId, KBFILTR_DEVICE_ID);

status = WdfPdoInitAddHardwareID(
                                 pDeviceInit,
                                 &hardwareId
                                 );
```

## See also

[WdfPdoInitAddCompatibleID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitaddcompatibleid)

[WdfPdoInitAssignDeviceID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitassigndeviceid)

[WdfPdoInitAssignInstanceID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitassigninstanceid)