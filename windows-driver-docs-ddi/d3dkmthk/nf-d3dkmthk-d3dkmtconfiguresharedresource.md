# D3DKMTConfigureSharedResource function

## Description

The **D3DKMTConfigureSharedResource** function configures a shared resource.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_CONFIGURESHAREDRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_configuresharedresource) structure that specifies parameters to configure the shared resource.

## Return value

**D3DKMTConfigureSharedResource** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The shared resource was successfully configured. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_NO_MEMORY | **D3DKMTConfigureSharedResource** could not complete because of insufficient memory. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_CONFIGURESHAREDRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_configuresharedresource)