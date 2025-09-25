# KsMapModuleName function

## Description

The **KsMapModuleName** function returns the image name and resource identifier that corresponds to the *PhysicalDeviceObject* and *ModuleName* parameters.

## Parameters

### `PhysicalDeviceObject` [in]

Pointer to a DEVICE_OBJECT for which to return the requested information.

### `ModuleName` [in]

Pointer to a buffer that contains the module name for which to return the requested information.

### `ImageName` [out]

A caller-allocated buffer that receives the image name for the specified resource.

### `ResourceId` [out]

Pointer to a caller-supplied variable that receives the resource identifier.

### `ValueType` [out]

Pointer to a location into which the function returns the value type of the specified resource.

## Return value

**KsMapModuleName** returns STATUS_SUCCESS if the requested values are found; otherwise, the routine returns an error code.

## See also

[KsGetImageNameAndResourceId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetimagenameandresourceid)