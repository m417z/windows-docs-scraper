## Description

Marshals an [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) object into the RPC buffer.

## Parameters

### `pFlags`

[in]

The data used by RPC.

### `pBuffer`

[in, out]

The current buffer. This pointer may or may not be aligned on entry.

### `ppidl`

[in]

The string.

## Return value

The value obtained from the returned **HRESULT** value is **S_OK**.

## See also

[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)