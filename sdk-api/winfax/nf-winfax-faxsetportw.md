# FaxSetPortW function

## Description

A fax client application calls the **FaxSetPort** function to change the configuration of the fax port of interest. The configuration data can include, among other items, the capability of the port, its priority, rings before answer, and the transmitting and called station identifiers..

## Parameters

### `FaxPortHandle` [in]

Type: **HANDLE**

Specifies a fax port handle returned by a call to the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function.

### `PortInfo` [in]

Type: **const [FAX_PORT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_port_infoa)***

Pointer to a [FAX_PORT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_port_infoa) structure. The structure contains data to modify the configuration of the specified fax port.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_PORT_SET](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_DEVICE_IN_USE** | The port indicated by the *FaxPortHandle* parameter is busy. |
| **ERROR_INVALID_PARAMETER** | One or both of the *FaxPortHandle* or *PortInfo* parameters are **NULL**. |

## Remarks

The application must call the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function and specify the **PORT_OPEN_MODIFY** access level before calling the **FaxSetPort** function.

Only the following members of the [FAX_PORT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_port_infoa) structure can be set using this function: Flags, Rings, Priority, Tsid, and Csid

A fax administration application typically calls the **FaxSetPort** function to administer the fax devices associated with the fax server. To query the devices, call the [FaxGetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetporta) function.

To obtain a valid port handle to specify in the *FaxPortHandle* parameter of the **FaxSetPort** function, call the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function. For more information, see [Fax Device Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-device-management).

> [!NOTE]
> The winfax.h header defines FaxSetPort as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_PORT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_port_infoa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnumPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumportsa)

[FaxGetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetporta)

[FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport)