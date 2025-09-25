# SLGetServiceInformation function

## Description

Gets global data information.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pwszValueName` [in]

Type: **PCWSTR**

The name associated with the value to retrieve. The following names are valid.

| Value | Meaning |
| --- | --- |
| **SL_INFO_KEY_VERSION**<br><br>L"Version" | Version of SL service. e.g. "1.2.3.4" |
| **SL_INFO_KEY_SYSTEM_STATE**<br><br>L"SystemState" | System State |
| **SL_INFO_KEY_ACTIVE_PLUGINS**<br><br>L"ActivePlugins" | Fully-qualified DLL paths for all active plugins (**NULL** delimited and double **NULL**-terminated) |
| **SL_INFO_KEY_SECURE_STORE_ID**<br><br>L"SecureStoreId" | Secure store ID (GUID) |
| **SL_INFO_KEY_SESSION_MACHINE_ID**<br><br>L"SessionMachineId" | Session machine ID (Binary BLOB) |

### `peDataType` [out, optional]

Type: **[SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype)***

A pointer to a value of the [SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype) enumeration that specifies the type of data in the *ppbValue* buffer.

| Value | Meaning |
| --- | --- |
| **SL_DATA_SZ** | **UNICODE** string |
| **SL_DATA_DWORD** | **DWORD** |
| **SL_DATA_BINARY** | Binary blob |
| **SL_DATA_MULTI_SZ** | Double null-terminated **UNICODE** string array |

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