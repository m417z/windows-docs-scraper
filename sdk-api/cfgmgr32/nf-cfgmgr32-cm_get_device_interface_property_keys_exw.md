# CM_Get_Device_Interface_Property_Keys_ExW function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_Device_Interface_Property_Keys](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_property_keysw) instead.]

The **CM_Get_Device_Interface_Property_Keys_ExW** function retrieves an array of device property keys that represent the device properties that are set for a device interface.

## Parameters

### `pszDeviceInterface` [in]

Pointer to a string that identifies the device interface instance to retrieve the property keys from.

### `PropertyKeyArray` [out, optional]

Pointer to a buffer that receives an array of [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey)-typed values, where each value is a device property key that represents a device property that is set for the device interface. The pointer is optional and can be NULL

### `PropertyKeyCount` [in, out]

The size, in [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey)-typed units, of the *PropertyKeyArray* buffer. If *PropertyKeyArray* is set to NULL, **PropertyKeyCount* must be set to zero. As output, if *PropertyKeyArray* is not large enough to hold all the property key data, **CM_Get_Device_Interface_Property_Keys_ExW** returns the count of the keys, in **PropertyKeyCount*.

### `ulFlags` [in]

Reserved. Must be set to zero.

### `hMachine` [in, optional]

Caller-supplied machine handle, obtained from a previous call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

**CM_Get_Device_Interface_Property_Keys_ExW** is part of the [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## See also

[CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew)

[SetupDiGetDeviceInterfacePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacepropertykeys)