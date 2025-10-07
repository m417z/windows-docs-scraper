# IdUlIMEStyle function

Identifies whether the specified non-color style has underline.

## Parameters

*pimestyle* \[in\]

An **IMESTYLE** structure returned from [**PIMEStyleFromAttr**](https://learn.microsoft.com/windows/win32/devnotes/pimestylefromattr) function.

## Return value

This function can returns one of the following values.

**IMESTY\_UL\_MIN** (2002)

**IMESTY\_UL\_NONE** (2002)

**IMESTY\_UL\_SINGLE** (2003)

**IMESTY\_UL\_DOTTED** (2005)

**IMESTY\_UL\_THICK** (2006)

**IMESTY\_UL\_LOWER** (2011)

**IMESTY\_UL\_THICKLOWER** (2012)

**IMESTY\_UL\_THICKDITHLOWER** (2013)

**IMESTY\_UL\_DITHLOWER** (2014)

**IMESTY\_UL\_MAX** (2014)

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Imeshare.dll |

## See also

[**PIMEStyleFromAttr**](https://learn.microsoft.com/windows/win32/devnotes/pimestylefromattr)

