# PFND3D12DDI_SHADERCACHESTOREVALUE_CB_0021 callback function

## Description

The **pfnShaderCacheStoreValueCb** callback function stores a value in the shader cache.

## Parameters

### `hRTDevice`

[in] Handle to the runtime's representation of the device.

### `hRTPSO`

[in] Handle to the runtime's representation of a pipeline state object.

### `pPrecomputedHash`

[in] Pointer to a [**D3D12DDI_SHADERCACHE_HASH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shadercache_hash) structure that contains a precomputed hash value used for cache insertion.

### `pKey`

[in] A pointer to the key associated with the value to be stored in the driver's shader cache. The key uniquely identifies the shader data in the cache.

### `KeyLen`

[in] The length of the key that **pKey** points to, in bytes.

### `pValue`

[in] A pointer to the data to be stored in the shader cache.

### `ValueLen`

[in] The length of the buffer that **pValue** points to, in bytes.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **pfnShaderCacheStoreValueCb** and [**pfnShaderCacheGetValueCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_shadercachegetvalue_cb_0021) callbacks are used to store and retrieve compiled shader code or other shader-related data in the driver's shader cache. Caching helps improve performance by reducing the need to recompile shaders that have already been compiled and cached.

Access this callback by using the [**D3D12DDI_SHADERCACHE_CALLBACKS_0021**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shadercache_callbacks_0021) structure.

## See also

[**D3D12DDI_SHADERCACHE_CALLBACKS_0021**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shadercache_callbacks_0021)

[**pfnShaderCacheGetValueCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_shadercachegetvalue_cb_0021)