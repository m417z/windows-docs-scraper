# SLGetInstalledProductKeyIds function

## Description

This function returns a list of product key IDs associated
with the specified Product SKU ID.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC session.

### `pProductSkuId` [in]

Type: **const SLID***

A pointer to the product SKU ID.

### `pnProductKeyIds` [out]

Type: **UINT***

A pointer to the number of product Key IDs returned.

### `ppProductKeyIds` [out]

Type: **SLID****

A pointer to an array of the product Key IDs.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The value for the input key was not found. |