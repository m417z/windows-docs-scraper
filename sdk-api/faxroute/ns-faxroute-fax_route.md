# FAX_ROUTE structure

## Description

The **FAX_ROUTE** structure contains information about a received fax document. The fax service passes the structure to a fax routing method in a call to the [FaxRouteMethod](https://learn.microsoft.com/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemethod) function.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies, in bytes, the size of the **FAX_ROUTE** structure. Before calling the [FaxRouteMethod](https://learn.microsoft.com/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemethod) function, the fax service sets this member to sizeof(FAX_ROUTE).

### `JobId`

Type: **DWORD**

Specifies a unique number that identifies the fax job that received the fax document.

### `ElapsedTime`

Type: **DWORDLONG**

Specifies a 64-bit unsigned integer that is the elapsed time, in UTC, for the fax job that received the fax document. This parameter represents the total time that elapses between the beginning of fax reception and the end of fax reception.

### `ReceiveTime`

Type: **DWORDLONG**

Specifies a 64-bit unsigned integer that is the starting time, in UTC, for the fax job that received the fax document.

### `PageCount`

Type: **DWORD**

Specifies the number of pages in the received fax document.

### `Csid`

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the called station identifier of the local fax device that received the fax document. This identifier is usually a telephone number.

### `Tsid`

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the transmitting station identifier of the remote fax device that sent the fax document. This identifier is usually a telephone number.

### `CallerId`

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that identifies the calling device that sent the fax document. This string may include the telephone number of the calling device.

### `RoutingInfo`

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the routing string for the received fax document. The string must be of the form:

`Canonical-Phone-Number[|Additional-Routing-Info]`

where `Canonical-Phone-Number` is defined in the [Address](https://learn.microsoft.com/windows/desktop/Tapi/address-ovr) topic of the TAPI documentation (see the Canonical Address subheading); and `Additional-Routing-Info` is the *subaddress* of a Canonical Address, and uses the subaddress format.

### `ReceiverName`

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the name of the person who received the fax document.

### `ReceiverNumber`

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the telephone number of the fax device that received the fax document.

### `DeviceName`

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the name of the device that received the fax document.

### `DeviceId`

Type: **DWORD**

Specifies the permanent line identifier for the receiving fax device.

### `RoutingInfoData`

Type: **LPBYTE**

Pointer to a buffer that contains additional routing data defined by the routing extension. For more information, see the following Remarks section.

### `RoutingInfoDataSize`

Type: **DWORD**

Specifies the size, in bytes, of the array pointed to by the **RoutingInfoData** member.

## Remarks

A fax routing method can call the [FaxRouteModifyRoutingData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemodifyroutingdata) callback function to change the routing information for a subsequent routing method. The function does this by modifying the **RoutingInfoData** member of the **FAX_ROUTE** structure that applies to the subsequent method. This allows a fax routing extension to retrieve user-defined routing data and to provide additional callback information to a different routing method. When the subsequent routing method executes, it processes the received fax transmission using the modified routing data. For more information, see **FaxRouteModifyRoutingData**.

The fax routing method can use the [FileTimeToLocalFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime) function, to convert from UTC to local time, and then use the [FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime) function to convert the local time to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. SYSTEMTIME contains individual members for month, day, year, weekday, hour, minute, second, and millisecond.

## See also

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-structures)

[FaxRouteMethod](https://learn.microsoft.com/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemethod)

[FaxRouteModifyRoutingData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemodifyroutingdata)