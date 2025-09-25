# ClusterNetInterfaceEnum function

## Description

Enumerates the [network interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) installed on a
cluster, returning one name with each call.

## Parameters

### `hNetInterfaceEnum` [in]

Handle to an existing enumeration object originally returned by the
[ClusterNetInterfaceOpenEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusternetinterfaceopenenum) function.

### `dwIndex` [in]

Index used to identify the entry to be enumerated. This parameter should be zero for the first call and then incremented for each subsequent
call.

### `lpszName` [out]

Pointer to a null-terminated Unicode string containing the name of the returned object.

### `lpcchName` [in, out]

Pointer to the size, in characters, of the *lpszName* buffer. On input,
specify the maximum number of characters the buffer can hold, including the terminating
**NULL**. On output, indicates the number of characters in the resulting name, excluding
the terminating **NULL**.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation completed successfully. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | No more data is available. This value is returned if there are no more objects to be returned. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | More data is available. This value is returned if the buffer pointed to by *lpszName* is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |