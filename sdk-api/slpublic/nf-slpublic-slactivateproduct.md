# SLActivateProduct function

## Description

Acquires a use license from the Software License Server (SLS).

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pProductSkuId` [in]

Type: **const SLID***

 A pointer to the product ID.

### `cbAppSpecificData` [in, optional]

Type: **UINT**

The size of application specific data.

### `pvAppSpecificData` [in, optional]

Type: **const PVOID**

A pointer to application specific data. The license server can use this
information to embed application specific run-time information.

### `pActivationInfo` [in, optional]

Type: **const [SL_ACTIVATION_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/slpublic/ns-slpublic-sl_activation_info_header)***

A pointer to additional product activation information.

### `pwszProxyServer` [in, optional]

Type: **PCWSTR**

The proxy server name. Set this to **NULL** to use automatic proxy discovery.

### `wProxyPort` [in, optional]

Type: **WORD**

The proxy server port. To use the default port, set *wProxyPort* to 0.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_PUBLISHING_LICENSE_NOT_INSTALLED**<br><br>0xC004F017 | The license is not installed. |
| **SL_E_PKEY_NOT_INSTALLED**<br><br>0xC004F014 | The product key is not available. |
| **SL_E_PRODUCT_SKU_NOT_INSTALLED**<br><br>0xc004f015 | The license is not installed. |