# PrjGetVirtualizationInstanceInfo function

## Description

Retrieves information about the virtualization instance.

## Parameters

### `namespaceVirtualizationContext` [in]

An opaque handle for the virtualization instance.

### `virtualizationInstanceInfo` [out]

On input points to a buffer to fill with information about the virtualization instance. On successful return the buffer is filled in.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

ProjFS callback routines provide the virtualization instance handle in their callbackData parameters. A provider that manages multiple virtualization instances can use the InstanceID field of virtualizationInstanceInfo to identify which of its virtualization instances is receiving the callback.

The provider can use the WriteAlignment member of virtualizationInstanceInfo to determine the correct values to use for the byteOffset and length parameters of [PrjWriteFileData](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjwritefiledata).