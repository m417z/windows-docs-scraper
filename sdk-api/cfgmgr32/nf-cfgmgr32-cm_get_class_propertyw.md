# CM_Get_Class_PropertyW function

## Description

The **CM_Get_Class_Property** function retrieves a device property that is set for a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) or [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes).

## Parameters

### `ClassGUID` [in]

Pointer to the GUID that identifies the [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) or [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) for which to retrieve a device property that is set for the device class. For information about specifying the class type, see the *ulFlags* parameter.

### `PropertyKey` [in]

Pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device property key of the requested device class property.

### `PropertyType` [out]

Pointer to a [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed variable that receives the property-data-type identifier of the requested device class property, where the property-data-type identifier is the bitwise OR between a base-data-type identifier and, if the base data type is modified, a property-data-type modifier.

### `PropertyBuffer` [out]

Pointer to a buffer that receives the requested device class property. **CM_Get_Class_Property** retrieves the requested property value only if the buffer is large enough to hold all the property value data. The pointer can be NULL.

### `PropertyBufferSize` [in, out]

The size, in bytes, of the *PropertyBuffer* buffer. If the *PropertyBuffer* parameter is set to NULL, **PropertyBufferSize* must be set to zero. As output, if the buffer is not large enough to hold all the property value data, **CM_Get_Class_Property** returns the size of the data, in bytes, in **PropertyBufferSize*.

### `ulFlags` [in]

Class property flags:

#### CM_CLASS_PROPERTY_INSTALLER

*ClassGUID* specifies a device setup class. Do not combine with CM_CLASS_PROPERTY_INTERFACE.

#### CM_CLASS_PROPERTY_INTERFACE

*ClassGUID* specifies a device interface class. Do not combine with CM_CLASS_PROPERTY_INSTALLER.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

**CM_Get_Class_Property** is part of the [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## See also

[SetupDiGetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyw)