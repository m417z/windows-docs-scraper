# FaxGetPortA function

## Description

The **FaxGetPort** function returns information for a specified fax port to a fax client application. The data includes, among other items, the permanent line identifier, the current status and capability of the port, and the transmitting and called station identifiers.

## Parameters

### `FaxPortHandle` [in]

Type: **HANDLE**

Specifies a fax port handle returned by a call to the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function.

### `PortInfo` [out]

Type: **PFAX_PORT_INFO***

Pointer to the address of a buffer to receive a [FAX_PORT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_port_infoa) structure. The structure describes one fax port. For information about memory allocation, see the following Remarks section.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or both of the *PortInfo* or *FaxPortHandle* parameters are **NULL**. |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_PORT_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

The application must call the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function and specify the **PORT_OPEN_QUERY** access level before calling the **FaxGetPort** function.

A fax administration application typically calls the **FaxGetPort** function to query a device associated with the fax server.

To obtain a valid port handle to specify in the *FaxPortHandle* parameter, call the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function.

The **FaxGetPort** function allocates the memory required for the [FAX_PORT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_port_infoa) buffer pointed to by the *PortInfo* parameter. An application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function to deallocate the resources associated with this parameter.

For more information, see [Fax Device Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-device-management) and [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

> [!NOTE]
> The winfax.h header defines FaxGetPort as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_PORT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_port_infoa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnumPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumportsa)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport)

[FaxSetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetporta)