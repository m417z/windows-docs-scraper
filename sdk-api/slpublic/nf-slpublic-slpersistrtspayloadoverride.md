# SLPersistRTSPayloadOverride function

## Description

Associates information with the specified product for both online and phone activation.

## Parameters

### `hSLC` [in]

Type: **HSLC**

Handle retrieved by previous call to the [SLOpen](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slopen) function.

### `pApplicationId` [in]

Type: **const SLID***

A pointer to the identifier of the application ID to be used for the fast policy queries.

### `pProductSkuId` [in, optional]

Type: **const SLID***

A pointer to the identifier of the ACID to be used for the fast policy queries.

### `pbData` [in]

Type: **BYTE***

A pointer to the byte data that will be sent during activation.

This function assumes the data is composed of a 20-bit value stored in the first three bytes:
Byte[0] is the LSB of the HIWORD, Byte[1] is the HSB of the LOWORD, and Byte[2] is the LSB of the LOWORD.
Any value composed of these three bytes that exceeds 20 bits will be rejected with **E_INVALIDARG**.

### `cbData` [in]

Type: **DWORD**

The number of bytes that will be stored. This must be set to 3.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |