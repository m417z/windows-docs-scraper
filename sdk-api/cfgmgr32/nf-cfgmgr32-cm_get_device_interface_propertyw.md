# CM_Get_Device_Interface_PropertyW function

## Description

The **CM_Get_Device_Interface_Property** function retrieves a device property that is set for a device interface.

## Parameters

### `pszDeviceInterface` [in]

Pointer to a string that identifies the device interface instance to retrieve the property from.

### `PropertyKey` [in]

Pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device interface property key of the device interface property to retrieve.

### `PropertyType` [out]

Pointer to a [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed variable that receives the property-data-type identifier of the requested device interface property. The property-data-type identifier is a bitwise OR between a base-data-type identifier and, if the base-data type is modified, a property-data-type modifier.

### `PropertyBuffer` [out]

A pointer to a buffer that receives the requested device interface property. **CM_Get_Device_Interface_Property** retrieves the requested property only if the buffer is large enough to hold all the property value data. The pointer can be NULL.

### `PropertyBufferSize` [in, out]

The size, in bytes, of the *PropertyBuffer* buffer. If *PropertyBuffer* is set to NULL, **PropertyBufferSize* must be set to zero. As output, if the buffer is not large enough to hold all the property value data, **CM_Get_Device_Interface_Property** returns the size of the data, in bytes, in **PropertyBufferSize*.

### `ulFlags` [in]

Reserved. Must be set to zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

**CM_Get_Device_Interface_Property** is part of the [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## See also

[SetupDiGetDeviceInterfaceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacepropertyw)