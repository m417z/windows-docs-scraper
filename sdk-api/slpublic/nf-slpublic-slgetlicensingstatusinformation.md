# SLGetLicensingStatusInformation function

## Description

Gets the licensing status of the specified application or SKU.

## Parameters

### `hSLC` [in]

Type: **HSLC**

Handle to the current SLC context.

### `pAppID` [in, optional]

Type: **const SLID***

A pointer to a **SLID** that represents the application ID.

| pAppID | pProductSkuId | Results |
| --- | --- | --- |
| **NULL** | **NULL** | Get previous right consumption result. |
| **NULL** | Not **NULL** | Get licensing status of this SKU. |
| Not **NULL** | **NULL** | Get licensing status of this application. |
| Not **NULL** | Not **NULL** | Get licensing status of this application/SKU. |

### `pProductSkuId` [in, optional]

Type: **const SLID***

A pointer to a **SLID** that represents the product ID.

| pAppID | pProductSkuId | Results |
| --- | --- | --- |
| **NULL** | **NULL** | Get previous right consumption result. |
| **NULL** | Not **NULL** | Get licensing status of this SKU. |
| Not **NULL** | **NULL** | Get licensing status of this application. |
| Not **NULL** | Not **NULL** | Get licensing status of this application/SKU. |

### `pwszRightName` [in, optional]

Type: **PCWSTR**

Must be **NULL**.

### `pnStatusCount` [out]

Type: **UINT***

A pointer to the number of the SKU's status.

### `ppLicensingStatus` [out]

Type: **[SL_LICENSING_STATUS](https://learn.microsoft.com/windows/desktop/api/slpublic/ns-slpublic-sl_licensing_status)****

A pointer to the licensing status of the SKU.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_RIGHT_NOT_CONSUMED**<br><br>0xC004F002 | The rights consumption failed. |