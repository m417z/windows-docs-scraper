# _PORT_DATA_1 structure

## Description

The [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) function uses a PORT_DATA_1 structure when it adds a port or configures an existing port.

## Members

### `sztPortName`

Specifies the name of the port. The MAX_PORTNAME_LEN constant is defined in tcpxcv.h.

### `dwVersion`

Specifies the version number of the PORT_DATA_1 structure, which is currently 1.

### `dwProtocol`

Specifies the protocol to use for the port. This value can be either PROTOCOL_RAWTCP_TYPE or PROTOCOL_LPR_TYPE, constants that are defined in tcpxcv.h.

### `cbSize`

Specifies the size, in bytes of this structure. Use **sizeof**(PORT_DATA_1) for this value.

### `dwReserved`

Reserved, must be set to zero.

### `sztHostAddress`

Specifies the IP Address or host name of the printer. The MAX_NETWORKNAME_LEN constant is defined in tcpxcv.h.

### `sztSNMPCommunity`

Specifies the SNMP community name of the printer. The MAX_SNMP_COMMUNITY_STR_LEN constant is defined in tcpxcv.h.

### `dwDoubleSpool`

If **TRUE**, indicates that double spooling is enabled. If **FALSE**, double spooling is disabled.

### `sztQueue`

Specifies the LPR queue name. The MAX_QUEUENAME_LEN constant is defined in tcpxcv.h.

### `sztIPAddress`

Specifies the IP address of the printer. The MAX_IPADDR_STR_LEN constant is defined in tcpxcv.h.

### `Reserved`

Reserved, must be set to zero.

### `dwPortNumber`

Specifies the port number of the device.

### `dwSNMPEnabled`

If **TRUE**, indicates that the device supports Simple Network Management Protocol (SNMP).

### `dwSNMPDevIndex`

Specifies the SNMP device index.

## Remarks

When the [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) function is called either to add a port or configure an existing port, its *pOutputData* parameter must be set with the address of a PORT_DATA_1 structure, which will be filled in when the function returns. To add a port, set this function's *pszDataName* parameter to the string L"AddPort". To configure a port, set this parameter to L"ConfigPort".

See [TCPMON Xcv Interface](https://learn.microsoft.com/windows-hardware/drivers/print/tcpmon-xcv-interface) for more information.

## See also

[XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85))