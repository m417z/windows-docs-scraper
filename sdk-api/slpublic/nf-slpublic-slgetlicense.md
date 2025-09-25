# SLGetLicense function

## Description

Returns the license file BLOB.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pLicenseFileId` [in]

Type: **const SLID***

A pointer to the license file ID.

### `pcbLicenseFile` [out]

Type: **UINT***

A pointer to the size, in bytes, of the license file BLOB.

### `ppbLicenseFile` [out]

Type: **PBYTE***

The license file BLOB.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_LICENSE_FILE_NOT_INSTALLED**<br><br>0xC004F011 | The license file is not installed. |