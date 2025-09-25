# ClusterRegEnumValue function

## Description

Enumerates the
values of an open [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key.

## Parameters

### `hKey` [in]

Handle of the cluster database key to enumerate.

### `dwIndex` [in]

Index used to identify the next value to be enumerated. This parameter should be zero for the first call to
**ClusterRegEnumValue** and then incremented for
subsequent calls.

Because values are not ordered, any new value has an arbitrary index. This means that
**ClusterRegEnumValue** may return values in any
order.

### `lpszValueName` [out]

Pointer to a null-terminated Unicode string containing the name of the returned value.

### `lpcchValueName` [in, out]

Pointer to the size of the *lpszValueName* buffer as a count of characters. On input,
specify the maximum number of characters the buffer can hold, including the terminating
**NULL**. On output, specifies the number of characters in the resulting name, excluding
the terminating **NULL**.

### `lpdwType` [out, optional]

Pointer to the type code for the value entry, or **NULL** if the type code is not
required. The type code can be one of the following values.

#### REG_BINARY (3)

Binary data in any form.

#### REG_DWORD (4)

A 32-bit number.

#### REG_DWORD_BIG_ENDIAN (5)

A 32-bit number stored in big-endian format.

#### REG_EXPAND_SZ (2)

A null-terminated Unicode string that contains unexpanded references to environment variables (for example,
"%PATH%").

#### REG_MULTI_SZ (6)

A sequence of null-terminated strings, terminated by an empty string (\0).

The following is an example:

*String1*\0*String2*\0*String3*\0*LastString*\0\0

The first \0 terminates the first string, the second to the last \0 terminates the last string, and the
final \0 terminates the sequence. Note that the final terminator must be factored into the length of the
string.

#### REG_NONE (0)

No defined value type.

#### REG_QWORD (11)

A 64-bit number.

#### REG_SZ (1)

A null-terminated Unicode string.

### `lpData` [out, optional]

Pointer to the data for the value entry. This parameter can be **NULL** if the data is
not required.

### `lpcbData` [in, out, optional]

On input, pointer to a count of bytes in the buffer pointed to by the *lpbData*
parameter. On output, pointer to a count of bytes resulting from the operation. This parameter can be
**NULL** only if *lpbData* is **NULL**.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 (0x0) | The operation was successful. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | There are no more values to be returned. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | One of the output buffers (*lpszValueName* or *lpbData*) is too small to hold the resulting data. The *lpcchValueName* and the *lpbData* parameters indicate the required size (note that *lpcchValueName* does not include the terminating **NULL** in the character count). |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation failed. |

## See also

[ClusterRegOpenKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregopenkey)