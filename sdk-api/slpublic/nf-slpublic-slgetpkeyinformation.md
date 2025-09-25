# SLGetPKeyInformation function

## Description

Gets the information of the specified product key.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pPKeyId` [in]

Type: **const SLID***

A pointer to the PKey ID.

### `pwszValueName` [in]

Type: **PCWSTR**

The name associated with the value to retrieve. The following names are valid.

| Value | Meaning |
| --- | --- |
| **SL_INFO_KEY_DIGITAL_PID**<br><br>L"DigitalPID" | Formatted PID structure for a PID4 |
| **SL_INFO_KEY_DIGITAL_PID2**<br><br>L"DigitalPID2" | Formatted PID structure for a PID2 |
| **SL_INFO_KEY_PARTIAL_PRODUCT_KEY**<br><br>L"PartialProductKey" | First 5 characters of product key |
| **SL_INFO_KEY_PRODUCT_SKU_ID**<br><br>L"ProductSkuId" | SKU SLID |
| **SL_INFO_KEY_CHANNEL**<br><br>L"Channel" | Channel ID |

### `peDataType` [out, optional]

Type: **[SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype)***

The data type.

| Value | Meaning |
| --- | --- |
| **SL_DATA_SZ** | UNICODE string |
| **SL_DATA_DWORD** | DWORD |
| **SL_DATA_BINARY** | Binary BLOB |

### `pcbValue` [out]

Type: **UINT***

A pointer to the size, in bytes, of the *ppbValue* buffer.

### `ppbValue` [out]

Type: **PBYTE***

A pointer to the data returned by SLC.
When finished using the memory, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_PKEY_NOT_INSTALLED**<br><br>0xC004F014 | The product key is not available. |
| **SL_E_NOT_SUPPORTED**<br><br>0xC004F016 | The request is not supported. |