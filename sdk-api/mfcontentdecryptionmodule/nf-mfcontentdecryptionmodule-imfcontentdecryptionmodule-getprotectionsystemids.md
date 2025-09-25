## Description

Gets a list of **SystemIDs** that the **IMFContentDecryptionModule** supports.

## Parameters

### `systemIds`

A **GUID** array in which the SystemIDs are returned.

### `count`

The count of SystemIDs returned in the *systemIds* parameter.

## Return value

Returns S_OK on success.

## Remarks

**SystemIDs** are identifiers used in the "cenc" Initialization Data Format. For more details, see ["cenc" Initialization Data Format](https://w3c.github.io/encrypted-media/format-registry/initdata/cenc.html).

The *systemIds* memory must be allocated and freed using [CoTaskMem](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc).

## See also