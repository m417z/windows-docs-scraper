# HSTRING_UserUnmarshal function

## Description

Unmarshals an [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring) object from the RPC buffer.

## Parameters

### `unnamedParam1`

TBD

### `unnamedParam2`

TBD

### `unnamedParam3`

TBD

#### - pBuffer [in]

The current buffer. This pointer may or may not be aligned on entry.

#### - pFlags [in]

The data used by RPC.

#### - ppidl [out]

The string.

## Return value

The value obtained from the returned **HRESULT** value is one of the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory for this function to perform. |

## See also

[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)