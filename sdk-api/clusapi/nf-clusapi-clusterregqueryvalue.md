# ClusterRegQueryValue function

## Description

Returns the
name, type, and data components associated with a value for an open
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key.

## Parameters

### `hKey` [in]

Handle of the cluster database key to query.

### `lpszValueName` [in]

Pointer to a null-terminated Unicode string containing the name of the value to be queried.

### `lpdwValueType` [out, optional]

Pointer to the key's value type. This parameter can be **NULL** if the type is not
required; otherwise, the value returned through this parameter is one of the following.

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

Pointer to the value's data. This parameter can be **NULL** if the data is not
required.

### `lpcbData` [in, out, optional]

On input, pointer to the count of bytes in the buffer pointed to by the *lpbData*
parameter. On output, pointer to the count of bytes in the value's data, which is placed in the content of
*lpbData* if the caller passes in a valid pointer.

The *lpbData* parameter can be **NULL** only if
*lpbData* is also **NULL**.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 (0x0) | The operation was successful. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The buffer pointed to by *lpbData* is not large enough to hold the data for the value. [ClusterRegQueryValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregqueryvalue) stores the required size in the content of *lpbData*. |

## Remarks

If *lpbData* is **NULL**, the
**ClusterRegQueryValue** function returns **ERROR_SUCCESS**
and stores the size of the value's data in the content of *lpbData*. This information
allows the caller to correctly allocate a buffer to hold the data.

If *lpdwValueType* is set to **REG_SZ**,
**REG_MULTI_SZ** or **REG_EXPAND_SZ**, then
*lpbData* also includes a **NULL** terminator.

## See also

[ClusterRegOpenKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregopenkey)