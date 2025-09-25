# WdfDeviceCreateSymbolicLink function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceCreateSymbolicLink** method creates a symbolic link to a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `SymbolicLinkName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a user-visible name for the device.

## Return value

If the operation succeeds, the **WdfDeviceCreateSymbolicLink** returns STATUS_SUCCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The system cannot allocate space to store the device name. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If a driver creates a symbolic link for a device, applications can use the symbolic link name to access the device. Typically, instead of providing symbolic links, framework-based drivers provide [device interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces) that applications can use to access their devices.

If the device is removed unexpectedly (surprise-removed), the framework removes the symbolic link to the device. The driver can then use the symbolic link name for a new instance of the device.

#### Examples

The following code example from a KMDF driver creates an [MS-DOS device name](https://learn.microsoft.com/windows-hardware/drivers/kernel/ms-dos-device-names) that an application can use to access a device.

```cpp
#define DOS_DEVICE_NAME  L"\\DosDevices\\MyDevice"
DECLARE_CONST_UNICODE_STRING(dosDeviceName, DOS_DEVICE_NAME);
NTSTATUS  status;

status = WdfDeviceCreateSymbolicLink(
                                     controlDevice,
                                     &dosDeviceName
                                     );
if (!NT_SUCCESS(status)) {
    goto Error;
}
```
A UMDF driver must provide a symbolic link name in the global **DosDevices** namespace, as the following code example illustrates.

```cpp
#define DOS_DEVICE_NAME  L"\\DosDevices\\Global\\MyDevice"
DECLARE_CONST_UNICODE_STRING(dosDeviceName, DOS_DEVICE_NAME);
NTSTATUS  status;

status = WdfDeviceCreateSymbolicLink(
                                     controlDevice,
                                     &dosDeviceName
                                     );
if (!NT_SUCCESS(status)) {
    goto Error;
}
```
For information about global and local **\DosDevices** namespaces, see [Local and Global MS-DOS Device Names](https://learn.microsoft.com/windows-hardware/drivers/kernel/local-and-global-ms-dos-device-names).

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)