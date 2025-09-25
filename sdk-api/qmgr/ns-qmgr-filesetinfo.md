# FILESETINFO structure

## Description

[Queue Manager (QMGR) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Background Intelligent Transfer Service (BITS)](https://learn.microsoft.com/windows/desktop/Bits/background-intelligent-transfer-service-portal).]

The **FILESETINFO** structure identifies the remote and local names of the file to download.

## Members

### `bstrRemoteFile`

Null-terminated string that contains the name of the file on the server (for example, **http://***ServerName***/***Path***/***FileName***.***ext*). The format of the name must conform to the transfer protocol you use. You cannot use wildcards in the path or file name. The URL must only contain legal URL characters; no escape processing is performed. The URL is limited to 2,200 characters, not including the terminating null character.

### `bstrLocalFile`

Null-terminated string that contains the name of the file on the client. The file name must include the full path, for example, **D:\\***MyApp***\\***UpdatesPath***\\***FileName***.***ext*. You cannot use wildcards in the path or file name, and directories in the path must exist. The path is limited to MAX_PATH, not including the terminating null character. The user must have permission to write to the local directory for downloads and uploads that request a reply. BITS does not support NTFS streams. Instead of using network drives, which are session specific, use UNC paths (for example, **\\***ServerName***\\***ShareName***\\***Path***\\***FileName***.***ext*).

### `dwSizeHint`

Not supported.