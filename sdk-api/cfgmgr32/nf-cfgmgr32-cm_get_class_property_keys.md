# CM_Get_Class_Property_Keys function

## Description

The **CM_Get_Class_Property_Keys** function retrieves an array of the device property keys that represent the device properties that are set for a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) or [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes).

## Parameters

### `ClassGUID` [in]

Pointer to the GUID that identifies the [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) or [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) for which to retrieve the property keys for. For information about specifying the class type, see the *ulFlags* parameter.

### `PropertyKeyArray` [out, optional]

Pointer to a buffer that receives an array of [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey)-typed values, where each value is a device property key that represents a device property that is set for the device class. The pointer is optional and can be NULL.

### `PropertyKeyCount` [in, out]

The size, in [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey)-typed units, of the *PropertyKeyArray* buffer. If *PropertyKeyArray* is set to NULL, **PropertyKeyCount* must be set to zero. As output, if *PropertyKeyArray* is not large enough to hold all the property key data, **CM_Get_Class_Property_Keys** returns the count of the keys, in **PropertyKeyCount*.

### `ulFlags` [in]

Class property key flags:

#### CM_CLASS_PROPERTY_INSTALLER

*ClassGUID* specifies a device setup class. Do not combine with CM_CLASS_PROPERTY_INTERFACE.

#### CM_CLASS_PROPERTY_INTERFACE

*ClassGUID* specifies a device interface class. Do not combine with CM_CLASS_PROPERTY_INSTALLER.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

**CM_Get_Class_Property_Keys** is part of the [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## See also

[SetupDiGetClassPropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertykeys)