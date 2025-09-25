# WdfPdoInitAssignContainerID function

## Description

[Applies to KMDF only]

The **WdfPdoInitAssignContainerID** method updates the container ID for a child device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `ContainerID` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a container ID string. The driver can allocate the string's buffer from paged pool.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The driver is initializing an FDO instead of a PDO. |
| **STATUS_INSUFFICIENT_RESOURCES** | The driver could not allocate space to store the container ID string. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For more information about container IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

The driver must call **WdfPdoInitAssignContainerID** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example initializes a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure, stores a Unicode string in the structure, and then registers the Unicode string as the device's container ID.

```cpp
UNICODE_STRING containerId = {0};

RtlInitUnicodeString(
                     &containerId,
                     strContainerId //Unicode string for container ID
                     );
status = WdfPdoInitAssignContainerID(
                                     pDeviceInit,
                                     &containerId
                                     );
```

## See also

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[WdfPdoInitAddCompatibleID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitaddcompatibleid)

[WdfPdoInitAddHardwareID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitaddhardwareid)

[WdfPdoInitAssignDeviceID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitassigndeviceid)

[WdfPdoInitAssignInstanceID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitassigninstanceid)