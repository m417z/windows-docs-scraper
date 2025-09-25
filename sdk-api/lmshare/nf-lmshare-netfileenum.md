# NetFileEnum function

## Description

Returns information about some or all open files on a server, depending on the parameters specified.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `basepath` [in]

Pointer to a string that specifies a qualifier for the returned information. If this parameter is **NULL**, all open resources are enumerated. If this parameter is not **NULL**, the function enumerates only resources that have the value of the *basepath* parameter as a prefix. (A prefix is the portion of a path that comes before a backslash.)

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `username` [in]

Pointer to a string that specifies the name of the user or the name of the connection. If the string begins with two backslashes ("\\"), then it indicates the name of the connection, for example, "\\127.0.0.1" or "\\ClientName". The part of the connection name after the backslashes is the same as the client name in the session information structure returned by the [NetSessionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessionenum) function. If the string does not begin with two backslashes, then it indicates the name of the user. If this parameter is not **NULL**, its value serves as a qualifier for the enumeration. The files returned are limited to those that have user names or connection names that match the qualifier. If this parameter is **NULL**, no user-name qualifier is used.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This parameter is a pointer to a string that specifies the name of the user. If this parameter is not **NULL**, its value serves as a qualifier for the enumeration. The files returned are limited to those that have user names matching the qualifier. If this parameter is **NULL**, no user-name qualifier is used.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **2** | Return the file identification number. The *bufptr* parameter points to an array of [FILE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-file_info_2) structures. |
| **3** | Return information about the file. The *bufptr* parameter points to an array of [FILE_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-file_info_3) structures. |

### `bufptr` [out]

Pointer to the address of the buffer that receives the information. The format of this data depends on the value of the *level* parameter.

This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with **ERROR_MORE_DATA**.

### `prefmaxlen` [in]

Specifies the preferred maximum length of returned data, in bytes. If you specify **MAX_PREFERRED_LENGTH**, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns **ERROR_MORE_DATA**. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

Pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint.

### `resume_handle` [in, out]

Pointer to a value that contains a resume handle which is used to continue an existing file search. The handle should be zero on the first call and left unchanged for subsequent calls. If this parameter is **NULL**, no resume handle is stored.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is not valid. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_BufTooSmall** | The supplied buffer is too small. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetFileEnum** function.

You can call the
[NetFileGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netfilegetinfo) function to retrieve information about a particular opening of a server resource.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling
**NetFileEnum**. For more information, see
[IADsResource](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsresource) and
[IADsFileServiceOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileserviceoperations).

## See also

[FILE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-file_info_2)

[FILE_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-file_info_3)

[NetFile
Functions](https://learn.microsoft.com/windows/desktop/NetShare/netfile-functions)

[NetFileGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netfilegetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)