# SLInstallProofOfPurchaseEx function

## Description

Register the product key with SL.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pApplicationId` [in]

Type: **const SLID***

A pointer to the application ID.

### `pProductSkuId` [in, optional]

Type: **const SLID***

A pointer to the product SKU ID.

### `pwszPKeyAlgorithm` [in]

Type: **PCWSTR**

The product key algorithm.

### `pwszPKeyString` [in]

Type: **PCWSTR**

The product key string.

### `cbPKeySpecificData` [in]

Type: **UINT**

The size, in bytes, of the product key specific data. If no PKey specific data exists, set *cbPKeySpecificData* to 0.

### `pbPKeySpecificData` [in, optional]

Type: **PBYTE**

A pointer to product key specific data. If no PKey specific data exists, set *pbPKeySpecificData* to **NULL**.

### `pPkeyId` [out]

Type: **SLID***

A pointer to the identifier of the registered product key. Used to reference PKey information.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **E_ACCESSDENIED**<br><br>0x80070005 | Access denied (API requires admin privileges). |
| **SL_E_LUA_ACCESSDENIED**<br><br>0xC004F025 | The action requires administrator privilege. |
| **SL_E_INVALID_PKEY**<br><br>0xC004F010 | The product key is not valid. |
| **SL_E_PRODUCT_SKU_NOT_INSTALLED**<br><br>0xC004F015 | The license is not installed. |
| **SL_E_PKEY_INVALID_UPGRADE**<br><br>0xC004F061 | This specified product key can only be used for upgrading, not for clean installations. |
| **SL_E_MISMATCHED_PRODUCT_SKU**<br><br>0xC004F069 | The product SKU is not found. |