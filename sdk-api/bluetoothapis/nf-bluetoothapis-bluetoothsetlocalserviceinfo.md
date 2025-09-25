# BluetoothSetLocalServiceInfo function

## Description

The
**BluetoothSetLocalServiceInfo** function sets local service information for a specific Bluetooth
radio.

## Parameters

### `hRadioIn` [in, optional]

A handle of the Bluetooth radio device to specify local service information for. If **NULL**,
**BluetoothSetLocalServiceInfo** searches for the first available local Bluetooth radio.

### `pClassGuid` [in]

The GUID of the service to expose. This should match the **GUID** in the server-side INF file.

### `ulInstance` [in]

An instance ID for the device node of the Plug and Play (PnP) ID.

### `pServiceInfoIn` [in]

A pointer to a [BLUETOOTH_LOCAL_SERVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_local_service_info_struct) structure that describes the local service to
set.

## Return value

The
**BluetoothSetLocalServiceInfo** function returns the following values:

| Return code | Description |
| --- | --- |
| **ERROR_NOT_FOUND** | The specified Bluetooth radio was not detected. |
| **ERROR_BAD_UNIT** | No Bluetooth radios were detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Sufficient resources were not available to complete the operation. You can receive this error when more than 100 local physical device objects (PDOs) correspond to Bluetooth services. |
| **STATUS_PRIVILEGE_NOT_HELD** | The caller does not have the required privileges. See the Remarks section for information about how to elevate privileges. |

## Remarks

**BluetoothSetLocalServiceInfo** is a user-mode API that is used only by profile driver developers to
trigger the installation of a local service that is described by the service **GUID** in
*pClassGuid*.

**BluetoothSetLocalServiceInfo** generates a Plug and Play (PnP) device ID in the form of "BTHENUM\{*ClassGuid*}". For example, "BTHENUM\{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}". User-mode applications
can call
**BluetoothSetLocalServiceInfo** subsequent times with the same service GUID but with a different
instance ID to create multiple instances of the specified server-side profile.

To use Bluetooth APIs like
**BluetoothSetLocalServiceInfo**, user-mode applications should link with
BthProps.lib.

**Warning** The process that calls
**BluetoothSetLocalServiceInfo** must have the **SE_LOAD_DRIVER_NAME** privilege. A process running in the
system or an administrator context can elevate its privilege by using the SDK
[LookupPrivilegeValue](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegevaluea) and
[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) functions. For more information about this see
[Installing a Bluetooth
Device](https://learn.microsoft.com/previous-versions/ff536681(v=vs.85)).

The [BLUETOOTH_LOCAL_SERVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_local_service_info_struct) structure is defined in the SDK
BluetoothApis.h header file.

## See also

[BLUETOOTH_LOCAL_SERVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_local_service_info_struct)