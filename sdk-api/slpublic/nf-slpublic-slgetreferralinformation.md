# SLGetReferralInformation function

## Description

Gets referral information for the specified product.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle retrieved by previous call to the [SLOpen](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slopen) function.

### `eReferralType` [in]

Type: **[SLREFERRALTYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-slreferraltype)**

The referral type.

### `pSkuOrAppId` [in]

Type: **const SLID***

A pointer to the **SLID** of the application or SKU from which to obtain information.

### `pwszValueName` [in]

Type: **PCWSTR**

The name associated with the value to retrieve. The following names are valid.

| Value | Meaning |
| --- | --- |
| **SL_PARTNERID** | Partner ID for the license reseller |
| **SL_REFERRALID** | Referral ID for the license reseller |
| **SL_MERCHANTCOMMERCEURL** | The merchant URL to purchase additional licenses |
| **SL_MERCHANTUPGRADEURL** | The merchant URL to purchase additional licenses |
| **SL_DOWNLOADURL** | A forward link to download the associated application |
| **SL_INSTALLATIONPARAMETERS** | Any parameters that are used when running the associated application's installer |
| **SL_MERCHANTSUPPORTPHONENUMBER** | The merchant support phone number(s) |
| **SL_MERCHANTSUPPORTEMAIL** | The merchant support email address |
| **SL_MERCHANTSUPPORTURL** | The merchant support URL |
| **SL_SERIALIZEDDATA** | A generic data BLOB |

### `ppwszValue` [out]

Type: **PWSTR***

The value to store. When finished using the memory, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |