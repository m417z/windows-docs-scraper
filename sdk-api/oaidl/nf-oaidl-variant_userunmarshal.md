# VARIANT_UserUnmarshal function

## Description

Unmarshals a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) object from the RPC buffer.

## Parameters

### `unnamedParam1` [in]

The data used by RPC.

### `unnamedParam2` [in]

The current buffer. This pointer may or may not be aligned on entry.

### `unnamedParam3` [out]

The object.

## Return value

The value obtained from the returned **HRESULT** value is one of the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *pVariant* parameter is not valid. |
| **RPC_X_BAD_STUB_DATA** | The stub data for the buffer size is incorrect. |
| **DISP_E_BADVARTYPE** | The input parameter is not a valid type of variant. |
| **E_OUTOFMEMORY** | Insufficient memory for this function to perform. |