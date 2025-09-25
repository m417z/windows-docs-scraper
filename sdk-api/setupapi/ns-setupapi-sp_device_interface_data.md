# SP_DEVICE_INTERFACE_DATA structure

## Description

An SP_DEVICE_INTERFACE_DATA structure defines a device interface in a device information set.

## Members

### `cbSize`

The size, in bytes, of the SP_DEVICE_INTERFACE_DATA structure. For more information, see the Remarks section.

### `InterfaceClassGuid`

The GUID for the class to which the device interface belongs.

### `Flags`

Can be one or more of the following:

#### SPINT_ACTIVE

The interface is active (enabled).

#### SPINT_DEFAULT

The interface is the default interface for the device class.

#### SPINT_REMOVED

The interface is removed.

### `Reserved`

Reserved. Do not use.

## Remarks

A SetupAPI function that takes an instance of the SP_DEVICE_INTERFACE_DATA structure as a parameter verifies whether the **cbSize** member of the supplied structure is equal to the size, in bytes, of the structure. If the **cbSize** member is not set correctly, the function will fail and set an error code of ERROR_INVALID_USER_BUFFER.

## See also

[SP_DEVICE_INTERFACE_DETAIL_DATA](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_device_interface_detail_data_a)

[SetupDiCreateDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfacea)

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)

[SetupDiGetDeviceInterfaceAlias](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacealias)

[SetupDiOpenDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinterfacea)

[SetupDiSetDeviceInterfaceDefault](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceinterfacedefault)