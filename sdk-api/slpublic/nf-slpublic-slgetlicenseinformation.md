# SLGetLicenseInformation function

## Description

Gets the specified license information.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pSLLicenseId` [in]

Type: **const SLID***

A pointer to the license ID.

### `pwszValueName` [in]

Type: **PCWSTR**

The name associated with the value to retrieve.. The following values are valid.

| Value | Meaning |
| --- | --- |
| **SL_INFO_KEY_DESCRIPTION**<br><br>L"Description" | The description of the license. |
| **SL_INFO_KEY_LICENSE_TYPE**<br><br>L"LicenseType" | The type of the license. |
| **SL_INFO_KEY_VERSION**<br><br>L"Version" | The version of the license. |

### `peDataType` [out, optional]

Type: **[SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype)***

A pointer to a value of the [SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype) enumeration that specifies the type of data in the *ppbValue* buffer. Acceptable values are:

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

If successful, the data is returned in the buffer allocated by SLC.
When finished using the memory, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The value for the input key was not found. |