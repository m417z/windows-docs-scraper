# LPSAFEARRAY_UserUnmarshal function

## Description

Unmarshals a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) object from the RPC buffer.

## Parameters

### `unnamedParam1` [in]

The data used by RPC.

### `unnamedParam2` [in, out]

The current buffer. This pointer may or may not be aligned on entry. The function aligns the buffer pointer, marshals the data, and returns the new buffer position, which is the address of the first byte after the marshaled object.

### `unnamedParam3` [in]

Receives the safe array that contains the data.

## Return value

The value obtained from the returned **HRESULT** value is one of the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **RPC_X_BAD_STUB_DATA** | The stub has received bad data. |
| **E_UNEXPECTED** | The array could not be found. |
| **E_OUTOFMEMORY** | Insufficient memory for this function to perform. |
| **DISP_E_BADCALLEE** | The [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) object does not have the correct dimensions, does not have the correct features, or memory cannot be reallocated. |