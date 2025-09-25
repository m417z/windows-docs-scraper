# SLGetServerStatus function

## Description

Checks the server status according to the specified
URL and RequestType.

## Parameters

### `pwszServerURL` [in]

Type: **PCWSTR**

The URL of the server.

### `pwszAcquisitionType` [in]

Type: **PCWSTR**

The acquisition type.

#### SL_INFO_KEY_SECURE_PROCESSOR_ACTIVATION_URL (L"SPCURL")

#### SL_INFO_KEY_RIGHT_ACCOUNT_ACTIVATION_URL (L"RACURL")

#### SL_INFO_KEY_PRODUCT_KEY_ACTIVATION_URL (L"PKCURL")

#### SL_INFO_KEY_USE_LICENSE_ACTIVATION_URL (L"EULURL")

#### SL_INFO_KEY_PRODUCT_ACTIVATION_URL (L"PAURL")

### `pwszProxyServer` [in, optional]

Type: **PCWSTR**

The proxy server name. Set to **NULL** for automatic proxy discovery.

### `wProxyPort` [in, optional]

Type: **WORD**

The proxy server port. Set to 0 to use the default port.

### `phrStatus` [out]

Type: **HRESULT***

A pointer to the server status.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |

## Remarks

Callers can either pass in the URL kept by themselves or get the SKU
specific URL by calling the [GetProductSkuInformation](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgetproductskuinformation) function and query each
URL.