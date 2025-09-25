# SHFormatDateTimeA function

## Description

[**SHFormatDateTime** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Produces a string representation of a time specified as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Parameters

### `pft` [in]

Type: **const FILETIME UNALIGNED***

A pointer to the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure whose time is to be converted to a string.

### `pdwFlags` [in, out, optional]

Type: **DWORD***

A pointer to a **DWORD** value that contains bitwise flags that specify the date and time format.

When you call the function, you can combine zero or more of the following flags, with exceptions as noted. You can also set this parameter to **NULL**, in which case the function assumes that the FDTF_DEFAULT flag is set.

#### FDTF_SHORTTIME (0x00000001)

0x00000001. Formats the time of day as specified by the **Regional and Language Options** application in Control Panel, but without seconds. This flag cannot be combined with FDTF_LONGTIME.

The short time was successfully formatted.

#### FDTF_SHORTDATE (0x00000002)

0x00000002. Formats the date as specified by the short date format in the **Regional and Language Options** application in Control Panel. This flag cannot be combined with FDTF_LONGDATE.

The short date was successfully formatted.

#### FDTF_DEFAULT

Equivalent to FDTF_SHORTDATE | FDTF_SHORTTIME.

#### FDTF_LONGDATE (0x00000004)

0x00000004. Formats the date as specified by the long date format in the **Regional and Language Options** application in Control Panel. This flag cannot be combined with FDTF_SHORTDATE.

The long date was successfully formatted.

#### FDTF_LONGTIME (0x00000008)

0x00000008. Formats the time of day as specified by the **Regional and Language Options** application in Control Panel, including seconds. This flag cannot be combined with FDTF_SHORTTIME.

The long time was successfully formatted.

#### FDTF_RELATIVE (0x00000010)

0x00000010. If the FDTF_LONGDATE flag is set and the date in the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure is the same date that **SHFormatDateTime** is called, then the day of the week (if present) is changed to "Today". If the date in the structure is the previous day, then the day of the week (if present) is changed to "Yesterday".

Relative notation was used for the date.

#### FDTF_LTRDATE (0x00000100)

0x00000100. Adds marks for left-to-right reading layout. This flag cannot be combined with FDTF_RTLDATE.

#### FDTF_RTLDATE (0x00000200)

0x00000200. Adds marks for right-to-left reading layout. This flag cannot be combined with FDTF_LTRDATE.

#### FDTF_NOAUTOREADINGORDER (0x00000400)

0x00000400. No reading order marks are inserted. Normally, in the absence of the FDTF_LTRDATE or FDTF_RTLDATE flag, **SHFormatDateTime** determines the reading order from the user's default locale, inserts reading order marks, and updates the *pdwFlags* output value appropriately. This flag prevents that process from occurring. It is used most commonly by legacy callers of **SHFormatDateTime**. This flag cannot be combined with FDTF_RTLDATE or FDTF_LTRDATE.

**Windows Server 2003 and Windows XP:** This value is not available.

When the function returns, the **DWORD** value pointed to by this parameter can contain zero or more of the following flags.

### `pszBuf` [out]

Type: **LPTSTR**

A pointer to a buffer that receives the formatted date and time. The buffer must be large enough to contain the number of TCHAR characters specified by the *cchBuf* parameter, including a terminating null character.

### `cchBuf`

Type: **UINT**

The number of TCHARs that can be contained by the buffer pointed to by *pszBuf*.

## Return value

Type: **int**

Returns the number of TCHARs written to the buffer, including the terminating null character. On failure, this value is 0.

## See also

[GetDateFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformata)

[GetTimeFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformata)

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHFormatDateTime as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).