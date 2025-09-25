# FaxConnectFaxServerA function

## Description

The **FaxConnectFaxServer** function connects a fax client application to the local fax server. The function returns a fax server handle that is required to call other fax client functions that facilitate job, device, configuration, and document management.

## Parameters

### `MachineName` [in, optional]

Type: **LPCTSTR**

This pointer must be **NULL** (an empty string), so that the application connects to the fax server on the local computer.

### `FaxHandle` [out]

Type: **LPHANDLE**

Pointer to a variable that receives a fax server handle that is required on subsequent calls to other fax client functions. If the fax server returns a null handle, it indicates an error.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *FaxHandle* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |
| **ERROR_ACCESS_DENIED** | The user under whose account the call was made does not have sufficient rights to the fax server. |

## Remarks

This function can only be used only with a local server. Use of a remote server is enabled in the [Fax Service Extended COM API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-service-extended-com-api). For more information see the [IFaxServer::Connect](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-connect-client-vb) method.

A fax client application must call the **FaxConnectFaxServer** function successfully before it calls any other fax client function.

The fax client application must call the [FaxClose](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxclose) function to disconnect from the fax server and deallocate the handle that the **FaxConnectFaxServer** function returns. For more information, see [Connecting to the Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-connecting-to-the-fax-server) and [Disconnecting from a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-disconnecting-from-a-fax-server).

> [!NOTE]
> The winfax.h header defines FaxConnectFaxServer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxClose](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxclose)