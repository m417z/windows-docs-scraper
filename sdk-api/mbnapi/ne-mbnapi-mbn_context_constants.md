# MBN_CONTEXT_CONSTANTS enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_CONTEXT_CONSTANTS** enumerated type specifies the maximum string lengths supported by members of the [MBN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_context) structure.

## Constants

### `MBN_ACCESSSTRING_LEN:100`

Maximum string length of the **accessString** member of the [MBN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_context) structure.

### `MBN_USERNAME_LEN:255`

Maximum string length of the **userName** member of the [MBN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_context) structure.

### `MBN_PASSWORD_LEN:255`

Maximum string length of the **password** member of the [MBN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_context) structure.

### `MBN_CONTEXT_ID_APPEND:0xffffffff`

 The device will find the appropriate index to store a context into.