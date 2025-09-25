# _D3DDDI_GETRESOURCEPRESENTPRIVATEDRIVERDATA structure

## Description

**D3DDDI_GETRESOURCEPRESENTPRIVATEDRIVERDATA** is used with [pfnGetResourcePresentPrivateDriverDataCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getresourcepresentprivatedriverdatacb) to query the resource private data, which is associated with the resource during Present.

## Members

### `hResource` [in]

A DirectX graphics kernel resource handle.

### `PrivateDriverDataSize` [in, out]

The size of the **pPrivateDriverData** buffer in bytes. When zero or when there is insufficient space, the size of the required buffer is returned back to the caller along with a **STATUS_INVALID_BUFFER_SIZE****HRESULT** value from the calling method.

**Note** By the time another call is made with the new buffer size, the resource could be associated with a different sized buffer.

### `pPrivateDriverData` [in, out]

The buffer where the private data will be written to.

## See also

[pfnGetResourcePresentPrivateDriverDataCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getresourcepresentprivatedriverdatacb)