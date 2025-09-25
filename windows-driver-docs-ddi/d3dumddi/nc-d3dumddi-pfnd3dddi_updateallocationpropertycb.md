# PFND3DDDI_UPDATEALLOCATIONPROPERTYCB callback function

## Description

The **pfnUpdateAllocationPropertyCb** functions updates the property of an allocation without creating a new allocation.

## Parameters

### `hDevice`

A handle to the display device associated with the allocation

### `unnamedParam2`

*pUpdateAllocationProperty* [in, out]

A pointer to a [D3DDDI_UPDATEALLOCPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_updateallocproperty) structure that describes how to update the allocation with the desired properties.

## Return value

**pfnUpdateAllocationPropertyCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The properties were successfully updated. The driver can start using the allocation with its new property immediately. PagingFenceValue is invalid, though the driver shouldn't wait on it.|
|STATUS_PENDING|The request has successfully been queued to VidMm and is being processed. The driver must synchronize against the returned PagingFenceValue before using the allocation with its new property. Note that if the driver request is invalid it may still fail at a later point, in which case the device will be put in error.|
|E_INVALIDARG|Invalid call with bad arguments provided.|
|E_OUTOFMEMORY|Desired supported memory segment is full.|
|E_FAIL|An unknown error has occurred.|