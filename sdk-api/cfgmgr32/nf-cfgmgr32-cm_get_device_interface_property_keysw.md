# CM_Get_Device_Interface_Property_KeysW function

## Description

The **CM_Get_Device_Interface_Property_Keys** function retrieves an array of device property keys that represent the device properties that are set for a device interface.

## Parameters

### `pszDeviceInterface` [in]

Pointer to a string that identifies the device interface instance to retrieve the property keys from.

### `PropertyKeyArray` [out, optional]

Pointer to a buffer that receives an array of [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey)-typed values, where each value is a device property key that represents a device property that is set for the device interface. The pointer is optional and can be NULL

### `PropertyKeyCount` [in, out]

The size, in [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey)-typed units, of the *PropertyKeyArray* buffer. If *PropertyKeyArray* is set to NULL, **PropertyKeyCount* must be set to zero. As output, if *PropertyKeyArray* is not large enough to hold all the property key data, **CM_Get_Device_Interface_Property_Keys** returns the count of the keys, in **PropertyKeyCount*.

### `ulFlags` [in]

Reserved. Must be set to zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

**CM_Get_Device_Interface_Property_Keys** is part of the [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## See also

[SetupDiGetDeviceInterfacePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacepropertykeys)