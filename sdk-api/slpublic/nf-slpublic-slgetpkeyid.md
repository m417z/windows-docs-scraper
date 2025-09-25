# SLGetPKeyId function

## Description

Gets the registered product key ID associated with the product.

## Parameters

### `hSLC` [in]

The handle to the current SLC context.

### `pwszPKeyAlgorithm` [in]

The product key algorithm.

### `pwszPKeyString` [in]

The product key string.

### `cbPKeySpecificData` [in]

The size, in bytes, of the product key specific data. If there is no PKey specific data, set *cbPKeySpecificData* to 0.

### `pbPKeySpecificData` [in]

A pointer to the product key specific data. If there is no PKey specific data, set *pbPKeySpecificData* to **NULL**.

### `pPKeyId` [out]

A pointer to the product key ID.

## Return value

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_PKEY_NOT_INSTALLED**<br><br>0xC004F014 | The product key is not available. |