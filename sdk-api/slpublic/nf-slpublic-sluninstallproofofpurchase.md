# SLUninstallProofOfPurchase function

## Description

Unregisters the product key information.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pPKeyId` [in]

Type: **const SLID***

A pointer to the identifier of the registered product key.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **E_ACCESSDENIED**<br><br>0x80070005 | Access denied (API requires admin privileges). |
| **SL_E_LUA_ACCESSDENIED**<br><br>0xC004F025 | The action requires administrator privilege. |
| **SL_E_PKEY_NOT_INSTALLED**<br><br>0xC004F014 | The product key is not available. |