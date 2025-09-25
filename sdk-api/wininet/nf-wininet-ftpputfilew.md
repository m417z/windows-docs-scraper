# FtpPutFileW function

## Description

Stores a file on the FTP server.

## Parameters

### `hConnect` [in]

Handle to an FTP session.

### `lpszLocalFile` [in]

Pointer to a null-terminated string that contains the name of the file to be sent from the local system.

### `lpszNewRemoteFile` [in]

Pointer to a null-terminated string that contains the name of the file to be created on the remote system.

### `dwFlags` [in]

Conditions under which the transfers occur. The application should select one transfer type and any of the flags that control how the caching of the file will be controlled.

The transfer type can be any one of the following values.

| Value | Meaning |
| --- | --- |
| **FTP_TRANSFER_TYPE_ASCII** | Transfers the file using FTP's ASCII (Type A) transfer method. Control and formatting information is converted to local equivalents. |
| **FTP_TRANSFER_TYPE_BINARY** | Transfers the file using FTP's Image (Type I) transfer method. The file is transferred exactly as it exists with no changes. This is the default transfer method. |
| **FTP_TRANSFER_TYPE_UNKNOWN** | Defaults to FTP_TRANSFER_TYPE_BINARY. |
| **INTERNET_FLAG_TRANSFER_ASCII** | Transfers the file as ASCII. |
| **INTERNET_FLAG_TRANSFER_BINARY** | Transfers the file as binary. |

The following values are used to control the caching of the file. The application can use one or more of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_FLAG_HYPERLINK** | Forces a reload if there was no Expires time and no LastModified time returned from the server when determining whether to reload the item from the network. |
| **INTERNET_FLAG_NEED_FILE** | Causes a temporary file to be created if the file cannot be cached. |
| **INTERNET_FLAG_RELOAD** | Forces a download of the requested file, object, or directory listing from the origin server, not from the cache. |
| **INTERNET_FLAG_RESYNCHRONIZE** | Reloads HTTP resources if the resource has been modified since the last time it was downloaded. All FTP resources are reloaded.<br><br>**Windows XP and Windows Server 2003 R2 and earlier:** Gopher resources are also reloaded. |

### `dwContext` [in]

Pointer to a variable that contains the application-defined value that associates this search with any application data. This parameter is used only if the application has already called
[InternetSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetstatuscallback) to set up a status callback.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**FtpPutFile** is a high-level routine that handles all the bookkeeping and overhead associated with reading a file locally and storing it on an FTP server. An application that needs to send file data only, or that requires close control over the file transfer, should use the
[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea) and
[InternetWriteFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetwritefile) functions.

If the
*dwFlags* parameter specifies **FILE_TRANSFER_TYPE_ASCII**, translation of the file data converts control and formatting characters to local equivalents.

Both
*lpszNewRemoteFile* and
*lpszLocalFile* can be either partially or fully qualified file names relative to the current directory.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FtpPutFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/ftp-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)