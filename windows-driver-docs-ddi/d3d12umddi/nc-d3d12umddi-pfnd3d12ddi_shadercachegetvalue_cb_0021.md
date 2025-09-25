# PFND3D12DDI_SHADERCACHEGETVALUE_CB_0021 callback function

## Description

The **pfnShaderCacheGetValueCb** callback function gets a value stored in the shader cache.

## Parameters

### `hRTDevice`

[in] Handle to the runtime's representation of the device.

### `hRTPSO`

[in] Handle to the runtime's representation of a pipeline state object.

### `pPrecomputedHash`

[in] A [**D3D12DDI_SHADERCACHE_HASH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shadercache_hash) structure that contains the hash value to use for cache lookup.

### `pKey`

[in] A pointer to the key associated with the value to be retrieved from the driver's shader cache. The key uniquely identifies the shader data in the cache.

### `KeyLen`

[in] The length of the key that **pKey** points to, in bytes.

### `pValue`

[out] A pointer to the compiled shader code or other data associated with the shader identified by **pPrecomputedHash** and **pKey**. This parameter can be NULL if **pValueLen** is zero.

### `pValueLen`

[in/out] Pointer to a variable that specifies the length of the buffer that **pValue** points to, in bytes. On input, this variable specifies the size of the buffer. On output, it specifies the size of the data that was written to the buffer. If **pValueLen** is set to zero and **pValue** is NULL, **pfnShaderCacheGetValueCb** should write the number of bytes needed for the data in a second call to it. Otherwise, if the buffer that **pValue** points to is too small, the function should fail.

## Return value

If **pfnShaderCacheGetValueCb** succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [**pfnShaderCacheStoreValueCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_shadercachestorevalue_cb_0021) and **pfnShaderCacheGetValueCb** callbacks are used to store and retrieve compiled shader code or other shader-related data in the driver's shader cache. Caching helps improve performance by reducing the need to recompile shaders that have already been compiled and cached.

Access this callback by using the [**D3D12DDI_SHADERCACHE_CALLBACKS_0021**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shadercache_callbacks_0021) structure.

## See also

[**D3D12DDI_SHADERCACHE_CALLBACKS_0021**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shadercache_callbacks_0021)

[**pfnShaderCacheStoreValueCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_shadercachestorevalue_cb_0021)