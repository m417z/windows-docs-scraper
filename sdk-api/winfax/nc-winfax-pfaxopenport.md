# PFAXOPENPORT callback function

## Description

The **FaxOpenPort** function returns a fax port handle to a fax client application. The port handle is required when the application calls other fax client functions that facilitate device management and fax document routing.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `DeviceId` [in]

Type: **DWORD**

Specifies a **DWORD** variable that is the permanent line identifier for the receiving device. Call the [FaxEnumPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumportsa) function to retrieve a valid value for this parameter. For more information, see the following Remarks section.

### `Flags` [in]

Type: **DWORD**

Specifies a **DWORD** variable that contains a set of bit flags that defines the access level for the port. This parameter can be one or more of the following values.

#### PORT_OPEN_QUERY

Port access level required to obtain a fax port handle. This access level is also required to call the [FaxGetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetporta) function to query fax port information.

#### PORT_OPEN_MODIFY

Port access level required to change the configuration of a fax port with a call to the [FaxGetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetporta) function. This access level also includes the access rights associated with the [PORT_OPEN_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-port-access-levels) access level.

### `FaxPortHandle` [out]

Type: **LPHANDLE**

Pointer to a variable that receives a fax port handle that is required on subsequent calls to other fax client functions. If the fax server returns a **NULL** handle, it indicates an error.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_PORT_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |
| **ERROR_INVALID_HANDLE** | The port has already been opened with [PORT_OPEN_MODIFY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-port-access-levels) access. |
| **ERROR_BAD_UNIT** | The *DeviceId* parameter is invalid. |

## Remarks

Call the **FaxOpenPort** function to obtain the handle to a fax port. Use the handle when you call the following functions:

* [FaxSetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetporta) to change the configuration of the port
* [FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa) to retrieve information about the fax routing methods associated with a device

The [FaxEnumPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumportsa) function returns an array of [FAX_PORT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_port_infoa) structures. Each structure contains detailed information for one port, including a valid value to pass in the *DeviceId* parameter. An application should not save this device identifier in a persistent manner, because the identifier can change between function calls to the fax server.

For more information, see [Fax Ports](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-ports), [Fax Device Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-device-management), and [Managing Fax Routing Data](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-routing-data).

## See also

[FAX_PORT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_port_infoa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxEnumPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumportsa)

[FaxGetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetporta)

[FaxInitializeEventQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxinitializeeventqueue)

[FaxSetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetporta)