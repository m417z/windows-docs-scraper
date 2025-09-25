# WdfPdoInitAssignInstanceID function

## Description

[Applies to KMDF only]

The **WdfPdoInitAssignInstanceID** method updates the [instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/instance-ids) for a child device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `InstanceID` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains an [instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/instance-ids) string. The driver can allocate the string's buffer from paged pool.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The driver is initializing an FDO instead of a PDO. |
| **STATUS_INSUFFICIENT_RESOURCES** | The driver could not allocate space to store the instance ID string. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For more information about instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

The driver must call **WdfPdoInitAssignInstanceID** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example converts a device's serial number to a Unicode string and then registers the Unicode string as the device's instance ID.

```cpp
DECLARE_UNICODE_STRING_SIZE(instanceID, INSTANCEID_LENGTH);

status =  RtlIntegerToUnicodeString(
                                    SerialNo,
                                    BASE_DEC,
                                    &instanceID
                                    );
status = WdfPdoInitAssignInstanceID(
                                    pDeviceInit,
                                    &instanceID
                                    );
```

## See also

[RtlIntegerToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlintegertounicodestring)

[WdfPdoInitAddCompatibleID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitaddcompatibleid)

[WdfPdoInitAddHardwareID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitaddhardwareid)

[WdfPdoInitAssignDeviceID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitassigndeviceid)