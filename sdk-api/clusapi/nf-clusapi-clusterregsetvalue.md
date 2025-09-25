# ClusterRegSetValue function

## Description

Sets a value for a
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key.

## Parameters

### `hKey` [in]

Handle to a cluster database key.

### `lpszValueName` [in]

Pointer to a null-terminated Unicode string containing the name of the value to set. If a value with this
name is not already present in the [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources),
**ClusterRegSetValue** adds it to the resource.

### `dwType` [in]

Type of information to be stored as the value's data. This parameter can be one of the following values. For more information see [Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types).

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

### `lpData` [in]

Pointer to the data to be stored with the name pointed to by *lpszValueName*.

### `cbData` [in]

Count of bytes in the data pointed to by the *lpbData* parameter. If the data is of
type **REG_SZ**, **REG_EXPAND_SZ** or
**REG_MULTI_SZ**, *cbData* must include the size of the
null-terminating character.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Do not call **ClusterRegSetValue** from the
following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ClusterRegSetValue** can be safely called from any
other resource DLL entry point function or from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ClusterRegOpenKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregopenkey)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)