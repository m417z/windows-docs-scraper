# BSTR_UserUnmarshal64 function

## Description

Unmarshals a [BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) object from the RPC buffer.

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
| **E_OUTOFMEMORY** | Insufficient memory for this function to perform. |