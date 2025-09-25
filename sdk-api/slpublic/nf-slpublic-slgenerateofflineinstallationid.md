# SLGenerateOfflineInstallationId function

## Description

Generates the Installation ID (IID).
Users can send the IID to CSR to get the Confirmation ID (CID).

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pProductSkuId` [in]

Type: **const SLID***

A pointer to the product ID.

### `ppwszInstallationId` [out]

Type: **PWSTR***

The Installation ID string. Once you are finished, call the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function to
free the memory.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_PKEY_NOT_INSTALLED**<br><br>0xC004F014 | The product key is not available. |