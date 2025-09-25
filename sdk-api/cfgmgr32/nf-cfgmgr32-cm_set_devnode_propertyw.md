# CM_Set_DevNode_PropertyW function

## Description

The **CM_Set_DevNode_Property** function sets a device instance property.

## Parameters

### `dnDevInst` [in]

Device instance handle that is bound to the local machine.

### `PropertyKey` [in]

Pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the property key of the device instance property to set.

### `PropertyType` [in]

A [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed value that represents the property-data-type identifier for the device instance property. To delete a property, this must be set to DEVPROP_TYPE_EMPTY.

### `PropertyBuffer` [in]

Pointer to a buffer that contains the property value of the device instance property. If either the property or the data is being deleted, this pointer must be set to NULL, and *PropertyBufferSize* must be set to zero.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer* buffer. If *PropertyBuffer* is set to NULL, *PropertyBufferSize* must be set to zero.

### `ulFlags` [in]

Reserved. Must be set to zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

**CM_Set_DevNode_Property** is part of the [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## See also

[SetupDiSetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdevicepropertyw)