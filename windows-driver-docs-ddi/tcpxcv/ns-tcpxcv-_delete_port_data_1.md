# _DELETE_PORT_DATA_1 structure

## Description

The [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) function uses a DELETE_PORT_DATA_1 structure when it deletes a port.

## Members

### `psztPortName`

Specifies the name of the port to be deleted. The MAX_PORTNAME_LEN constant is defined in tcpxcv.h.

### `Reserved`

Is reserved for system use.

### `dwVersion`

Specifies the version of this structure, which is currently 1.

### `dwReserved`

Is obsolete, and must be set to 0.

## Remarks

When the [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) function is called to delete a port, its *pInputData* parameter must be set with the address of a DELETE_PORT_DATA_1 structure. Set this function's *pszDataName* parameter to the string L"DeletePort".

See [TCPMON Xcv Interface](https://learn.microsoft.com/windows-hardware/drivers/print/tcpmon-xcv-interface) for more information.

## See also

[XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85))