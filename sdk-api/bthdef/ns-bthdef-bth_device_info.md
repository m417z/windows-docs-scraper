# BTH_DEVICE_INFO structure

## Description

The **BTH_DEVICE_INFO** structure stores information about a Bluetooth device.

## Members

### `flags`

A combination of one or more of the flags listed in the following table.

| Value | Meaning |
| --- | --- |
| **BDIF_ADDRESS** | The **address** member contains valid data. |
| **BDIF_COD** | The **classOfDevice** member contains valid data. |
| **BDIF_NAME** | The **name** member contains valid data. |
| **BDIF_PAIRED** | The device is a remembered and authenticated device. The **BDIF_PERSONAL** flag is always set when this flag is set. |
| **BDIF_PERSONAL** | The device is a remembered device. If this flag is set and the **BDIF_PAIRED** flag is not set, the device is not authenticated. |
| **BDIF_CONNECTED** | The remote Bluetooth device is currently connected to the local radio. |
| **BDIF_SSP_SUPPORTED** | The device supports the use of Secure Simple Pairing (SSP). |
| **BDIF_SSP_PAIRED** | The device is remembered and is authenticated using Secure Simple Pairing (SSP). |
| **BDIF_SSP_MITM_PROTECTED** | The device supports the use of Secure Simple Pairing (SSP) to protect against "Man in the Middle" attacks. |

### `address`

Address of the remote Bluetooth device.

### `classOfDevice`

Bit field that describes the device class of device (COD) of the remote device. The COD consists of the following four fields:

Format: retrieved using GET_COD_FORMAT(**classOfDevice**). The only format currently supported is COD_VERSION.

Major: retrieved using the GET_COD_MAJOR(**classOfDevice**). The following values are currently defined, but the list is expected to expand. Do not use the major class field to determine to which remote device to connect. A remote device may only have one major class code, and may not be the appropriate code for the given profile.

#### COD_MAJOR_MISCELLANEOUS

#### COD_MAJOR_COMPUTER

#### COD_MAJOR_PHONE

#### COD_MAJOR_LAN_ACCESS

#### COD_MAJOR_AUDIO

#### COD_MAJOR_PERIPHERAL

#### COD_MAJOR_IMAGING

#### COD_MAJOR_UNCLASSIFIED

Minor: retrieved using GET_COD_MINOR(**classOfDevice**). The minor code is specific to each major code, which defines how its minor code is formatted. Some minor codes are strictly enumerated values; others are bit fields or a combination of bit fields and enumerated values.

Service hints: retrieved using the GET_COD_SERVICE(**classOfDevice**). Provides hints about the capability of the remote device.

#### COD_SERVICE_LIMITED

#### COD_SERVICE_POSITIONING

#### COD_SERVICE_NETWORKING

#### COD_SERVICE_RENDERING

#### COD_SERVICE_CAPTURING

#### COD_SERVICE_OBJECT_XFER

#### COD_SERVICE_AUDIO

#### COD_SERVICE_TELEPHONY

#### COD_SERVICE_INFORMATION

### `name`

Name of the remote Bluetooth device, as reported by the device, encoded in UTF8. The user may have locally provided a display name for the remote Bluetooth device; that name is overridden, and does not appear in this member; it is accessible only with a call to the
[BluetoothGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetdeviceinfo) function.

## See also

[BTH_QUERY_DEVICE](https://learn.microsoft.com/windows/desktop/api/ws2bth/ns-ws2bth-bth_query_device)

[BTH_QUERY_SERVICE](https://learn.microsoft.com/windows/desktop/api/ws2bth/ns-ws2bth-bth_query_service)

[BTH_SET_SERVICE](https://learn.microsoft.com/windows/desktop/api/ws2bth/ns-ws2bth-bth_set_service)

[BluetoothGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetdeviceinfo)