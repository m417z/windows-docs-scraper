# SLGetLicenseFileId function

## Description

Checks if the license BLOB has been
installed already.

## Parameters

### `hSLC` [in]

The handle to the current SLC context.

### `cbLicenseBlob` [in]

The size, in bytes, of the license BLOB.

### `pbLicenseBlob` [in]

A pointer to the number of licenses in the BLOB.

### `pLicenseFileId` [out]

A pointer to the license file ID.

## Return value

If the License has been previously installed, it returns a **SLID**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_INVALID_LICENSE**<br><br>0xC004F01F | The license is not valid. |
| **SL_E_LICENSE_FILE_NOT_INSTALLED**<br><br>0xC004F011 | The license file is not installed. |