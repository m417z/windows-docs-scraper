# PathIsSlowW function

## Description

[**PathIsSlow** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Determines whether a file path is a high-latency network connection.

## Parameters

### `pszFile` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the fully qualified path of the file.

### `dwAttr`

Type: **DWORD**

The file attributes, if known; otherwise, pass –1 and this function gets the attributes by calling [GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa). See **GetFileAttributes** for a list of file attributes.

## Return value

Type: **BOOL**

Returns **TRUE** if the connection is high-latency; otherwise, **FALSE**.

## Remarks

A path is considered slow if the MultinetGetConnectionPerformance function returns a dwSpeed of 400 or less in its [NETCONNECTINFOSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netconnectinfostruct) structure—this is the speed of the media to the network resource, in 100 bits-per-second (bps)—or if FILE_ATTRIBUTE_OFFLINE is set on the file.

Note that network conditions can impact function performance time.

> [!NOTE]
> The shlobj.h header defines PathIsSlow as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).