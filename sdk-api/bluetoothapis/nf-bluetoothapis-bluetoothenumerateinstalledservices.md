# BluetoothEnumerateInstalledServices function

## Description

The **BluetoothEnumerateInstalledServices** function enumerates the services GUIDs (Globally Unique Identifiers) enabled on a Bluetooth device.

## Parameters

### `hRadio`

Handle of the local Bluetooth radio device. If **NULL**, all local radios are searched for enabled services that match the radio address in *pbtdi*.

### `pbtdi`

Pointer to a [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure.

### `pcServiceInout`

On input, the number of records pointed to by the *pGuidServices* parameter. On output, the number of valid records returned in the *pGuidServices* parameter. If pGuidServices is **NULL**, on output *pcServices* contains the number of services enabled.

### `pGuidServices`

Pointer to a buffer in memory to receive GUIDs for installed services. The buffer must be at least **pcServices* ***sizeof**(GUID) bytes.

## Return value

Returns ERROR_SUCCESS upon successful completion, and the pGuidServices parameter contains a complete list of enabled service GUIDs.

The following table describes a common error:

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The call succeeded. The *pGuidServices* parameter contains an incomplete list of enabled service GUIDs. |

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BLUETOOTH_DEVICE_SEARCH_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_search_params)

[BluetoothDisplayDeviceProperties](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothdisplaydeviceproperties)

[BluetoothFindDeviceClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfinddeviceclose)

[BluetoothFindFirstDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstdevice)

[BluetoothFindNextDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextdevice)

[BluetoothGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetdeviceinfo)

[BluetoothRemoveDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothremovedevice)