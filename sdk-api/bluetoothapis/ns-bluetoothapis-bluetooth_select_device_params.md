# BLUETOOTH_SELECT_DEVICE_PARAMS structure

## Description

The
**BLUETOOTH_SELECT_DEVICE_PARAMS** structure facilitates and manages the visibility, authentication, and selection of Bluetooth devices and services.

## Members

### `dwSize`

Size, in bytes, of the
**BLUETOOTH_SELECT_DEVICE_PARAMS** structure.

### `cNumOfClasses`

Number of classes in **prgClassOfDevices**. Set to zero to search for all devices.

### `prgClassOfDevices`

Array of class of devices to find.

### `pszInfo`

Sets the information text when not **NULL**.

### `hwndParent`

Handle to the parent window. Set to **NULL** for no parent.

### `fForceAuthentication`

If **TRUE**, forces authentication before returning.

### `fShowAuthenticated`

If **TRUE**, authenticated devices are shown in the picker.

### `fShowRemembered`

If **TRUE**, remembered devices are shown in the picker.

### `fShowUnknown`

If **TRUE**, unknown devices that are not authenticated or remembered are shown in the picker.

### `fAddNewDeviceWizard`

If **TRUE**, starts the Add New Device wizard.

### `fSkipServicesPage`

If **TRUE**, skips the Services page in the Add New Device wizard.

### `pfnDeviceCallback`

A pointer to a callback function that is called for each device. If the callback function returns **TRUE**, the item is added. If the callback function returns **FALSE**, the item is not shown. Set **pfnDeviceCallback** to null for no callback. For more information, see [PFN_DEVICE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nc-bluetoothapis-pfn_device_callback).

### `pvParam`

Parameter to be passed as **pvParam** to the callback function pointed to in **pfnDeviceCallback**.

### `cNumDevices`

On input, specifies the number of desired calls. Set to zero for no limit. On output, returns the number of devices returned.

### `pDevices`

Pointer to an array of
[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structures.

## Remarks

To free the array of
[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structures passed in the **pDevices** member, call the
[BluetoothSelectDevicesFree](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothselectdevicesfree) function.

## See also

[BLUETOOTH_COD_PAIRS](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-bluetooth_cod_pairs)

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BluetoothSelectDevices](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothselectdevices)

[BluetoothSelectDevicesFree](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothselectdevicesfree)

[PFN_DEVICE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nc-bluetoothapis-pfn_device_callback)