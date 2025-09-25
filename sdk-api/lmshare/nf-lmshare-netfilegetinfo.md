# NetFileGetInfo function

## Description

Retrieves information about a particular opening of a server resource.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `fileid` [in]

Specifies the file identifier of the open resource for which to return information. The value of this parameter must have been returned in a previous enumeration call. For more information, see the following Remarks section.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **2** | Return the file identification number. The *bufptr* parameter is a pointer to a [FILE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-file_info_2) structure. |
| **3** | Return the file identification number and other information about the file. The *bufptr* parameter is a pointer to a [FILE_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-file_info_3) structure. |

### `bufptr` [out]

Pointer to the address of the buffer that receives the information. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_FILE_NOT_FOUND** | The file was not found. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_BufTooSmall** | The supplied buffer is too small. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetFileGetInfo** function.

You can call the
[NetFileEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netfileenum) function to retrieve information about multiple files open on a server.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling
**NetFileGetInfo**. For more information, see
[IADsResource](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsresource) and
[IADsFileServiceOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileserviceoperations).

## See also

[FILE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-file_info_2)

[FILE_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-file_info_3)

[NetFile
Functions](https://learn.microsoft.com/windows/desktop/NetShare/netfile-functions)

[NetFileEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netfileenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)