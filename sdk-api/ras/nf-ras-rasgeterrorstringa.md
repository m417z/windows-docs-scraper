# RasGetErrorStringA function

## Description

The
**RasGetErrorString** function obtains an error message string for a specified RAS error value.

## Parameters

### `ResourceId` [in]

Specifies the error value of interest. These are values returned by one of the RAS functions: those listed in the RasError.h header file.

### `lpszString` [out]

Pointer to a buffer that receives the error string. This parameter must not be **NULL**.

### `InBufSize` [in]

Specifies the size, in characters, of the buffer pointed to by *lpszErrorString*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h. There is no [GetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-iabcontainer-getlasterror) information set by the
**RasGetErrorString** function.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed into the function. |

## Remarks

There is no way to determine in advance the exact size in characters of an error message, and thus the size of buffer required. Error messages will generally be 80 characters or fewer in size; a buffer size of 512 characters will always be adequate. A buffer of insufficient size causes the
**RasGetErrorString** function to fail, returning **ERROR_INSUFFICIENT_BUFFER**. Note that buffer sizes are specified in characters, not bytes; thus, the Unicode version of
**RasGetErrorString** requires at least a 1024 byte buffer to guarantee that every error message fits.

#### Examples

The following code obtains an error string for the RAS error 633.

```cpp

#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include "rasdlg.h"
#include <tchar.h>

#define  ERROR_VAL 633
#define  BUFFER_SIZE 256

DWORD __cdecl wmain(){

    DWORD dwRetVal = ERROR_SUCCESS;
    UINT  uErrorValue = ERROR_VAL;
    DWORD cBufSize = BUFFER_SIZE;
    WCHAR lpszErrorString[BUFFER_SIZE];

    dwRetVal = RasGetErrorString(uErrorValue, lpszErrorString, cBufSize);

    if(dwRetVal == ERROR_SUCCESS){
        wprintf(L"Error Code %d: %s\n", uErrorValue, lpszErrorString);
    }else{
           wprintf(L"RasGetErrorString failed, Return Value: %d", dwRetVal);
    }

    return 0;
}

```

> [!NOTE]
> The ras.h header defines RasGetErrorString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc)

[LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)