# SLSetAuthenticationData function

## Description

Sets authentication data.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `cbValue` [in, optional]

Type: **UINT**

The size, in bytes, of the authentication data in *pbValue*.

### `pbValue` [in, optional]

Type: **const BYTE**

A pointer to the authentication data.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **ERROR_INVALID_DATA**<br><br>0x8007000D | The format of authentication data is not valid. |
| **SL_E_AUTHN_WRONG_VERSION**<br><br>0xC004F077 | The security version is wrong. |
| **SL_E_NOT_SUPPORTED**<br><br>0xC004F016 | The authentication data format is not supported. |