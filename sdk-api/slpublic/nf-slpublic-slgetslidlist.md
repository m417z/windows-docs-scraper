# SLGetSLIDList function

## Description

Gets a list of **SLID**s according to the input query ID type and the ID value.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `eQueryIdType` [in]

Type: **[SLIDTYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-slidtype)**

The type of input ID.

### `pQueryId` [in, optional]

Type: **const SLID***

A pointer to the input ID.

### `eReturnIdType` [in]

Type: **[SLIDTYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-slidtype)**

The type of returned IDs.

### `pnReturnIds` [out]

Type: **UINT***

A pointer to the number of returned IDs.

### `ppReturnIds` [out]

Type: **SLID****

An array of returned IDs.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The value for the input key was not found. |
| **SL_E_NOT_SUPPORT**<br><br>0xC004F016 | The request is not supported. |

## Remarks

The following queries combinations are supported.

| eQueryIdType | pQueryId | eReturnIdType | Results |
| --- | --- | --- | --- |
| **SL_ID_APPLICATION** | SLID_ALL | **SL_ID_APPLICATION** | Get all installed application IDs. |
| **SL_ID_PRODUCT_SKU** | SLID_ALL | **SL_ID_PRODUCT_SKU** | Get all installed product SKU IDs. |
| **SL_ID_APPLICATION** | appId | **SL_ID_PRODUCT_SKU** | Get SKU IDs according to the input application ID. |
| **SL_ID_PRODUCT_SKU** | skuId | **SL_ID_APPLICATION** | Get application IDs according to the input SKU ID. |
| **SL_ID_PRODUCT_SKU** | skuId | **SL_ID_PKEY** | Get license PKey IDs according to the input SKU ID. |
| **SL_ID_PRODUCT_SKU** | skuId | **SL_ID_LICENSE_FILE** | Get license file Ids according to the input SKU ID. |
| **SL_ID_LICENSE_FILE** | fileId | **SL_ID_LICENSE** | Get license IDs according to the input license file ID. |
| **SL_ID_LICENSE** | LicenseId | **SL_ID_LICENSE_FILE** | Get license file ID according to the input license ID. |
| **SL_ID_LICENSE** | LicenseId | **SL_ID_APPLICATION** | Get union of all application IDs or SKU IDs from all grants of a token activation license. Returns **SL_E_NOT_SUPPORTED** if the license ID is valid but doesn't refer to a token activation license. |
| **SL_ID_LICENSE** | LicenseId | **SL_ID_PRODUCT_SKU** | Get union of all application IDs or SKU IDs from all grants of a token activation license. Returns **SL_E_NOT_SUPPORTED** if the license ID is valid but doesn't refer to a token activation license. |