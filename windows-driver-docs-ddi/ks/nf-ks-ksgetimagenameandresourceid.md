# KsGetImageNameAndResourceId function

## Description

The **KsGetImageNameAndResourceId** function returns the image name and resource identifier that corresponds to the *RegKey* handle.

## Parameters

### `RegKey` [in]

Specifies a handle for which to return the image name and resource identifier.

### `ImageName` [out]

A caller-allocated buffer that receives the image name for the specified resource.

### `ResourceId` [out]

Pointer to a caller-supplied variable that receives the resource identifier.

### `ValueType` [out]

Pointer to a location into which the function returns the value type of the specified resource.

## Return value

**KsGetImageNameAndResourceId** returns STATUS_SUCCESS if the requested values are found; otherwise, an error code is returned.

## See also

[KsMapModuleName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmapmodulename)