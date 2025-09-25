# CM_Get_Class_Property_ExW function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Get_Class_Property](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_class_propertyw) instead.]

The **CM_Get_Class_Property_ExW** function retrieves a device property that is set for a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) or [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes).

## Parameters

### `ClassGUID` [in]

Pointer to the GUID that identifies the [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) or [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) for which to retrieve a device property that is set for the device class. For information about specifying the class type, see the *ulFlags* parameter.

### `PropertyKey` [in]

Pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device property key of the requested device class property.

### `PropertyType` [out]

Pointer to a [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed variable that receives the property-data-type identifier of the requested device class property, where the property-data-type identifier is the bitwise OR between a base-data-type identifier and, if the base data type is modified, a property-data-type modifier.

### `PropertyBuffer` [out]

Pointer to a buffer that receives the requested device class property. **CM_Get_Class_Property_ExW** retrieves the requested property value only if the buffer is large enough to hold all the property value data. The pointer can be NULL.

### `PropertyBufferSize` [in, out]

The size, in bytes, of the *PropertyBuffer* buffer. If the *PropertyBuffer* parameter is set to NULL, **PropertyBufferSize* must be set to zero. As output, if the buffer is not large enough to hold all the property value data, **CM_Get_Class_Property_ExW** returns the size of the data, in bytes, in **PropertyBufferSize*.

### `ulFlags` [in]

Class property flags:

#### CM_CLASS_PROPERTY_INSTALLER

*ClassGUID* specifies a device setup class. Do not combine with CM_CLASS_PROPERTY_INTERFACE.

#### CM_CLASS_PROPERTY_INTERFACE

*ClassGUID* specifies a device interface class. Do not combine with CM_CLASS_PROPERTY_INSTALLER.

### `hMachine` [in]

Caller-supplied machine handle, obtained from a previous call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

**CM_Get_Class_Property_ExW** is part of the [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## See also

[CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew)

[SetupDiGetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyw)

[SetupDiGetClassPropertyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyexw)