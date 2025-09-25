# PFN_AUTHENTICATION_CALLBACK callback function

## Description

The **PFN_AUTHENTICATION_CALLBACK** function is a callback function prototype used in conjunction with the [BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication) function.

**Note** When developing for Windows Vista SP2 and Windows 7 the use of [PFN_AUTHENTICATION_CALLBACK_EX](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nc-bluetoothapis-pfn_authentication_callback_ex) is recommended.

## Parameters

### `pvParam`

Optional. A context pointer previously passed into the [BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication) function.

### `pDevice`

A remote Bluetooth device requesting authentication. The remote address is the same address used to register the callback during the previous call to the [BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication) function.

## Return value

The return value from this function is ignored by the system.

## Remarks

A caller can register for multiple addresses with the same callback function.

## See also

[BluetoothRegisterForAuthentication](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothregisterforauthentication)