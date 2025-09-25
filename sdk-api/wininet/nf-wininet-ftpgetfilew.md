# FtpGetFileW function

## Description

Retrieves a file from the FTP server and stores it under the specified file name, creating a new local file in the process.

## Parameters

### `hConnect` [in]

Handle to an FTP session.

### `lpszRemoteFile` [in]

Pointer to a null-terminated string that contains the name of the file to be retrieved.

### `lpszNewFile` [in]

Pointer to a null-terminated string that contains the name of the file to be created on the local system.

### `fFailIfExists` [in]

Indicates whether the function should proceed if a local file of the specified name already exists. If
*fFailIfExists* is **TRUE** and the local file exists,
**FtpGetFile** fails.

### `dwFlagsAndAttributes` [in]

File attributes for the new file. This parameter can be any combination of the FILE_ATTRIBUTE_* flags used by the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `dwFlags` [in]

Controls how the function will handle the file download. The first set of flag values indicates the conditions under which the transfer occurs. These transfer type flags can be used in combination with the second set of flags that control caching.

The application can select one of these transfer type values.

| Value | Meaning |
| --- | --- |
| **FTP_TRANSFER_TYPE_ASCII** | Transfers the file using FTP's ASCII (Type A) transfer method. Control and formatting information is converted to local equivalents. |
| **FTP_TRANSFER_TYPE_BINARY** | Transfers the file using FTP's Image (Type I) transfer method. The file is transferred exactly as it exists with no changes. This is the default transfer method. |
| **FTP_TRANSFER_TYPE_UNKNOWN** | Defaults to FTP_TRANSFER_TYPE_BINARY. |
| **INTERNET_FLAG_TRANSFER_ASCII** | Transfers the file as ASCII. |
| **INTERNET_FLAG_TRANSFER_BINARY** | Transfers the file as binary. |

The following flags determine how the caching of this file will be done. Any combination of the following flags can be used with the transfer type flag.

| Value | Meaning |
| --- | --- |
| **INTERNET_FLAG_HYPERLINK** | Forces a reload if there was no Expires time and no LastModified time returned from the server when determining whether to reload the item from the network. |
| **INTERNET_FLAG_NEED_FILE** | Causes a temporary file to be created if the file cannot be cached. |
| **INTERNET_FLAG_RELOAD** | Forces a download of the requested file, object, or directory listing from the origin server, not from the cache. |
| **INTERNET_FLAG_RESYNCHRONIZE** | Reloads HTTP resources if the resource has been modified since the last time it was downloaded. All FTP resources are reloaded.<br><br>**Windows XP and Windows Server 2003 R2 and earlier:** Gopher resources are also reloaded. |

### `dwContext` [in]

Pointer to a variable that contains the application-defined value that associates this search with any application data. This is used only if the application has already called
[InternetSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetstatuscallback) to set up a status callback function.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**FtpGetFile** is a high-level routine that handles all the bookkeeping and overhead associated with reading a file from an FTP server and storing it locally. An application that needs to retrieve file data only or that requires close control over the file transfer should use the
[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea) and
[InternetReadFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetreadfile) functions.

If the
*dwFlags* parameter specifies **FTP_TRANSFER_TYPE_ASCII**, translation of the file data converts control and formatting characters to local equivalents. The default transfer is binary mode, where the file is downloaded in the same format as it is stored on the server.

Both
*lpszRemoteFile* and
*lpszNewFile* can be either partially or fully qualified file names relative to the current directory.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FtpGetFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/ftp-sessions)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)