# D3DKMTRegisterTrimNotification function

## Description

**D3DKMTRegisterTrimNotification** is used by a kernel mode video memory manager to register and implement a callback for each kernel mode device to receive notifications from a graphics framework (such as OpenGL).

**Note** The callback must be unregistered prior to unloading the module that contains the callback function and destroying the registered kernel mode device.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_REGISTERTRIMNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_registertrimnotification) structure that describes the operation.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The operation was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMTUnregisterTrimNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtunregistertrimnotification)

[D3DKMT_REGISTERTRIMNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_registertrimnotification)