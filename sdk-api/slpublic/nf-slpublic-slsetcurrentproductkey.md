# SLSetCurrentProductKey function

## Description

Sets the current
product key to the previously installed product key.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pProductSkuId` [in]

Type: **const SLID***

A pointer to the product SKU ID.

### `pProductKeyId` [in]

Type: **const SLID***

A pointer to the product key ID.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **SL_E_MISMATCHED_PRODUCT_SKU**<br><br>0xC004F069 | The product SKU is not found. |
| **SL_E_PKEY_NOT_INSTALLED**<br><br>0xC004F014 | The product key is not available. |
| **SL_E_OPERATION_NOT_ALLOWED**<br><br>0xC004F06A | The requested operation is not allowed. |