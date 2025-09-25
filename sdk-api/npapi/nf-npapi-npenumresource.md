# NPEnumResource function

## Description

Performs an enumeration based on a handle returned by
[NPOpenEnum](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npopenenum).

## Parameters

### `hEnum` [in]

Handle obtained from an
[NPOpenEnum](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npopenenum) call.

### `lpcCount` [in, out]

Pointer to the number of entries requested. It may be 0xFFFFFFFF to request as many entries as possible. If the call succeeds, this location will receive the number of entries actually read.

### `lpBuffer` [out]

Pointer to the buffer to receive the enumeration result, which is returned as an array of
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) entries. The buffer is valid until the next call using *hEnum*.

### `lpBufferSize` [in, out]

Pointer to the size, in bytes, of the buffer passed to the function call on entry. If the buffer is too small for even one entry, this should contain, on exit, the number of bytes needed to read one entry. This value is set only if the return code is WN_MORE_DATA.

## Return value

If the function succeeds, it should return WN_SUCCESS. The caller may continue to call **NPEnumResource** to continue the enumeration. Otherwise, it should return one of the following error codes.

| Return code | Description |
| --- | --- |
| **WN_NO_MORE_ENTRIES** | No more entries. The enumeration was completed successfully. When this occurs, the contents of the return buffer, *lpBuffer*, are undefined. |
| **WN_MORE_DATA** | The buffer is too small to hold even a single entry. |
| **WN_BAD_HANDLE** | *hEnum* is not a valid handle. |
| **WN_NO_NETWORK** | The network is not present. This condition is checked before *hEnum* is tested for validity. |

## Remarks

When this function is called, the provider should fill the buffer with the requested number of entries (or the maximum that can fit). The returned
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) structures should be located contiguously at the head of the buffer, like an array of such structures. The pointers in these structures must point to locations within the buffer. Therefore, data referenced by these pointers should be located at the end of the buffer, after the array of structures. It is the provider's responsibility to package this information correctly.