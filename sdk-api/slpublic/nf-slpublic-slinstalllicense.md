# SLInstallLicense function

## Description

Stores the specified license and returns a license file ID.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `cbLicenseBlob` [in]

Type: **UINT**

Size of license BLOB.

### `pbLicenseBlob` [in]

Type: **const BYTE***

A pointer to the licenses in the BLOB.

### `pLicenseFileId` [out]

Type: **SLID***

A pointer to the license file ID.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **E_ACCESSDENIED**<br><br>0x80070005 | Access denied (API requires admin privileges). |
| **SL_E_LUA_ACCESSDENIED**<br><br>0xC004F025 | The action requires administrator privilege. |
| **SL_E_INVALID_LICENSE**<br><br>0xC004F01F | The license is not valid. |