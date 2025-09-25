# HSTRING_UserSize64 function

## Description

Calculates the wire size of the [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring) object, and gets its handle and data.

## Parameters

### `unnamedParam1` [in]

The data used by RPC.

### `unnamedParam2` [in]

The current buffer offset where the object will be marshaled. The method has to account for any padding needed for the [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring) object to be properly aligned when it will be marshaled to the buffer.

### `unnamedParam3` [in]

The string.

## Return value

The value obtained from the returned **HRESULT** value is **S_OK**.

## See also

[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)