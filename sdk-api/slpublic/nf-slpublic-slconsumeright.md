# SLConsumeRight function

## Description

Let an application to exercise rights on a locally-stored licenses. Calling this function binds a license to the right.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pAppId` [in]

Type: **const SLID***

A pointer to the identifier of the application who's right is going to be
consumed.

### `pProductSkuId` [in, optional]

Type: **const SLID***

A pointer to the identifier of product SKU. If set to **NULL**, all of the product SKU's
licenses will be consumed.

### `pwszRightName` [in, optional]

Type: **PCWSTR**

The name of right to be consumed.

### `pvReserved`

Type: **PVOID**

Reserved.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_RIGHT_NOT_GRANTED**<br><br>0xC004F013 | The caller does not have permission to run the software. |
| **SL_E_PRODUCT_SKU_NOT_INSTALLED**<br><br>0xC004F015 | The license is not installed. |