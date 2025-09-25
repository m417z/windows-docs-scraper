# GOPHER_FIND_DATAA structure

## Description

[The **GOPHER_FIND_DATA** structure is available for use in the operating systems specified in the Requirements section.]

Contains information retrieved by the
[GopherFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopherfindfirstfilea) and
[InternetFindNextFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetfindnextfilea) functions.

## Members

### `DisplayString`

Friendly name of an object. An application can display this string to allow the user to select the object.

### `GopherType`

Describes the item returned. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GOPHER_TYPE_ASK** | Ask+ item. |
| **GOPHER_TYPE_BINARY** | Binary file. |
| **GOPHER_TYPE_BITMAP** | Bitmap file. |
| **GOPHER_TYPE_CALENDAR** | Calendar file. |
| **GOPHER_TYPE_CSO** | CSO telephone book server. |
| **GOPHER_TYPE_DIRECTORY** | Directory of additional Gopher items. |
| **GOPHER_TYPE_DOS_ARCHIVE** | MS-DOS archive file. |
| **GOPHER_TYPE_ERROR** | Indicator of an error condition. |
| **GOPHER_TYPE_GIF** | GIF graphics file. |
| **GOPHER_TYPE_GOPHER_PLUS** | Gopher+ item. |
| **GOPHER_TYPE_HTML** | HTML document. |
| **GOPHER_TYPE_IMAGE** | Image file. |
| **GOPHER_TYPE_INDEX_SERVER** | Index server. |
| **GOPHER_TYPE_INLINE** | Inline file. |
| **GOPHER_TYPE_MAC_BINHEX** | Macintosh file in BINHEX format. |
| **GOPHER_TYPE_MOVIE** | Movie file. |
| **GOPHER_TYPE_PDF** | PDF file. |
| **GOPHER_TYPE_REDUNDANT** | Indicator of a duplicated server. The information contained within is a duplicate of the primary server. The primary server is defined as the last directory entry that did not have a GOPHER_TYPE_REDUNDANT type. |
| **GOPHER_TYPE_SOUND** | Sound file. |
| **GOPHER_TYPE_TELNET** | Telnet server. |
| **GOPHER_TYPE_TEXT_FILE** | ASCII text file. |
| **GOPHER_TYPE_TN3270** | TN3270 server. |
| **GOPHER_TYPE_UNIX_UUENCODED** | UUENCODED file. |
| **GOPHER_TYPE_UNKNOWN** | Item type is unknown. |

### `SizeLow`

Low 32 bits of the file size.

### `SizeHigh`

High 32 bits of the file size.

### `LastModificationTime`

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time when the file was last modified.

### `Locator`

File locator. An application can pass the locator string to
[GopherOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopheropenfilea) or
[GopherFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopherfindfirstfilea).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines GOPHER_FIND_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GopherFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopherfindfirstfilea)

[InternetFindNextFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetfindnextfilea)