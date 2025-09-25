# VARIANT_UserMarshal function

## Description

Marshals a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) object into the RPC buffer.

## Parameters

### `unnamedParam1` [in]

The data used by RPC.

### `unnamedParam2` [in, out]

The current buffer. This pointer may or may not be aligned on entry.

### `unnamedParam3` [in]

The object.

## Return value

The value obtained from the returned **HRESULT** value is one of the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *pVariant* parameter is not valid. |
| **RPC_X_NULL_REF_POINTER** | The *pVariant* parameter is null. |
| **DISP_E_BADVARTYPE** | The input parameter is not a valid type of variant. |