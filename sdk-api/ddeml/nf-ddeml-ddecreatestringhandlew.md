# DdeCreateStringHandleW function

## Description

Creates a handle that identifies the specified string. A Dynamic Data Exchange (DDE) client or server application can pass the string handle as a parameter to other Dynamic Data Exchange Management Library (DDEML) functions.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `psz` [in]

Type: **LPTSTR**

The null-terminated string for which a handle is to be created. This string can be up to 255 characters. The reason for this limit is that DDEML string management functions are implemented using atoms.

### `iCodePage` [in]

Type: **int**

The code page to be used to render the string. This value should be either **CP_WINANSI** (the default code page) or CP_WINUNICODE, depending on whether the ANSI or Unicode version of [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) was called by the client application.

## Return value

Type: **HSZ**

If the function succeeds, the return value is a string handle.

If the function fails, the return value is 0L.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

The value of a string handle is not related to the case of the string it identifies.

When an application either creates a string handle or receives one in the callback function and then uses the [DdeKeepStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddekeepstringhandle) function to keep it, the application must free that string handle when it is no longer needed.

An instance-specific string handle cannot be mapped from string handle to string and back to string handle. This is shown in the following example, in which the [DdeQueryString](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequerystringa) function creates a string from a string handle and **DdeCreateStringHandle** creates a string handle from that string, but the two handles are not the same:

```
DWORD idInst;
DWORD cb;
HSZ hszInst, hszNew;
PSZ pszInst;

DdeQueryString(idInst, hszInst, pszInst, cb, CP_WINANSI);
hszNew = DdeCreateStringHandle(idInst, pszInst, CP_WINANSI);
// hszNew != hszInst !
```

> [!NOTE]
> The ddeml.h header defines DdeCreateStringHandle as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[DdeAccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeaccessdata)

[DdeCmpStringHandles](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecmpstringhandles)

[DdeFreeStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreestringhandle)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[DdeKeepStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddekeepstringhandle)

[DdeQueryString](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequerystringa)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**