# CM_Set_Class_PropertyW function

## Description

The **CM_Set_Class_Property** function sets a class property for a device setup class or a device interface class.

## Parameters

### `ClassGUID` [in]

Pointer to the GUID that identifies the [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) or [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) for which to set a device property. For information about specifying the class type, see the *ulFlags* parameter.

### `PropertyKey` [in]

Pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the property key of the device class property to set.

### `PropertyType` [in]

A [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed value that represents the property-data-type identifier for the device class property. To delete a property, set this to DEVPROP_TYPE_EMPTY.

### `PropertyBuffer` [in]

Pointer to a buffer that contains the property value of the device class property. If either the property or the data is to be deleted, this pointer must be set to NULL, and *PropertyBufferSize* must be set to zero.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer* buffer. If *PropertyBuffer* is set to NULL, *PropertyBufferSize* must be set to zero.

### `ulFlags` [in]

Class property flags:

#### CM_CLASS_PROPERTY_INSTALLER

*ClassGUID* specifies a device setup class. Do not combine with CM_CLASS_PROPERTY_INTERFACE.

#### CM_CLASS_PROPERTY_INTERFACE

*ClassGUID* specifies a device interface class. Do not combine with CM_CLASS_PROPERTY_INSTALLER.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

**CM_Set_Class_Property** is part of the [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## See also

[SetupDiSetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclasspropertyw)