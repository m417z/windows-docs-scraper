# CM_Get_DevNode_PropertyW function

## Description

The **CM_Get_DevNode_Property** function retrieves a device instance property.

## Parameters

### `dnDevInst` [in]

Device instance handle that is bound to the local machine.

### `PropertyKey` [in]

Pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device property key of the requested device instance property.

### `PropertyType` [out]

Pointer to a [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed variable that receives the property-data-type identifier of the requested device instance property, where the property-data-type identifier is the bitwise OR between a base-data-type identifier and, if the base-data type is modified, a property-data-type modifier.

### `PropertyBuffer` [out]

Pointer to a buffer that receives the requested device instance property. **CM_Get_DevNode_Property** retrieves the requested property only if the buffer is large enough to hold all the property value data. The pointer can be NULL.

### `PropertyBufferSize` [in, out]

The size, in bytes, of the *PropertyBuffer* buffer. If *PropertyBuffer* is set to NULL, **PropertyBufferSize* must be set to zero. As output, if the buffer is not large enough to hold all the property value data, **CM_Get_DevNode_Property** returns the size of the data, in bytes, in **PropertyBufferSize*.

### `ulFlags` [in]

Reserved. Must be set to zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

**CM_Get_DevNode_Property** is part of the [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## See also

[SetupDiGetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertyw)