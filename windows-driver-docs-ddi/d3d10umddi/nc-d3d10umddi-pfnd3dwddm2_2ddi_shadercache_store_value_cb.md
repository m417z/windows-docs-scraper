# PFND3DWDDM2_2DDI_SHADERCACHE_STORE_VALUE_CB callback function

## Description

The *pfnShaderCacheStoreValue* callback function stores a shader cache value.

## Parameters

### `hCacheSession`

The handle of the cache session for the driver to use when it calls back into the runtime.

### `pPrecomputedHash`

A hash value.

### `pKey`

A pointer to a key.

### `KeyLen`

The length of the key.

### `pValue`

A pointer to an input value.

### `ValueLen`

The length of the input value.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.