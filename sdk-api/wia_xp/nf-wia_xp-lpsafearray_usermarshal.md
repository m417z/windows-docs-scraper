# LPSAFEARRAY_UserMarshal function

## Description

Marshals data from the specified [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) object to the user's RPC buffer on the client or server side.

## Parameters

### `unnamedParam1` [in]

The data used by RPC.

### `unnamedParam2` [in, out]

The current buffer. This pointer may or may not be aligned on entry. The function aligns the buffer pointer, marshals the data, and returns the new buffer position, which is the address of the first byte after the marshaled object.

### `unnamedParam3` [in]

The safe array that contains the data to marshal.

## Return value

The value obtained from the returned **HRESULT** value is one of the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *ppSafeArray* parameter is not a valid safe array. |
| **E_UNEXPECTED** | The array could not be locked. |