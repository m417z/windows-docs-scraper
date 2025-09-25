# BTH_SET_SERVICE structure

## Description

The
**BTH_SET_SERVICE** structure provides service information for the specified Bluetooth service.

## Members

### `pSdpVersion`

Version of the SDP. Clients set this member to
BTH_SDP_VERSION.

### `pRecordHandle`

Handle to the SDP record. Corresponds to SDP ServiceRecordHandle. Returned by the add record operations, and subsequently used to delete the record.

### `fCodService`

Class of device (COD) information. A 32-bit field of COD_SERVICE_* class of device bits associated with this SDP record. The system combines these bits with COD bits from other service records and system characteristics. The resulting class of device for the local radio is advertised when the radio is found during device inquiry. When the last SDP record associated with a particular service bit is deleted, that service bit is no longer reported in responses to future device inquiries.

The format and possible values for the COD field are defined in the *Bluetooth Assigned Numbers 1.1* portion of the Bluetooth specification, Section 1.2. (This resource may not be available in some languages and countries.) Corresponding macros and definitions for COD_SERVICE_* bits used by Windows are defined in Bthdef.h. For more information about class of device (COD), see [BTH_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/bthdef/ns-bthdef-bth_device_info).

### `Reserved`

Reserved. Must be set to zero.

### `ulRecordLength`

Size, in bytes, of **pRecord**.

### `pRecord`

SDP record, as defined by the Bluetooth specification.

## Remarks

When using the
**BTH_SET_SERVICE** structure to query services and devices using the
[WSASetService](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsasetservice) function and
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsaqueryset-for-service-inquiry) and
[BLOB](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-blob) structures. The following values for
**BTH_SET_SERVICE** members must be used.

For more information about class of device (COD), see the Bluetooth specification at
[www.bluetooth.com](https://www.bluetooth.com/).

| Member | Required value |
| --- | --- |
| **pSdpVersion** | Pointer to ULONG version, which is changed whenever the binary format of SDP records change, affecting the format of the **pRecord** member. Set to **BTH_SDP_VERSION** for the client, and returned by the system. |
| **pRecordHandle** | Handle to the SDP record; corresponds to SDP ServiceRecordHandle. Returned by the add record operations, and subsequently used to delete the record. |
| **fOptions** | Attributes defined by **BTHNS_SET_FLAGS**. |
| **ulRecordLength** | Length, in bytes, of the binary SDP record pointed to by **pRecord**. |
| **pRecord** | Pointer to a valid SDP record, in the format defined by the Bluetooth specification. |

The **pRecordHandle** member must point to data that is null for new service registration. For service deletion, **pRecordHandle** must point to a valid handle. The **pRecord** member must contain the entire SD service record, as described in the Bluetooth specification. For RFCOMM protocol entries, the port number is the same as the port returned by the
[getsockname](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-getsockname) function call.

Bluetooth implements a one-to-one correlation between SDP records and server sockets. As such, there is no need for the **SERVICE_MULTIPLE** flag.

## See also

[Bluetooth
and getsockname](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-getsockname)

[Bluetooth and
BLOB](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-blob)

[Bluetooth and WSASetService](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsasetservice)

[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsaqueryset-for-service-inquiry)