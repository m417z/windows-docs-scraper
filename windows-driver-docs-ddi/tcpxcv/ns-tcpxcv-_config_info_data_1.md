# _CONFIG_INFO_DATA_1 structure

## Description

The [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) function uses a CONFIG_INFO_DATA_1 structure when it obtains configuration data for a particular port.

## Members

### `Reserved`

Is reserved for system use. This member should be set to a zero-length string.

### `dwVersion`

Specifies the version of the PORT_DATA_1 structure (currently equal to 1) that will contain the configuration information.

## Remarks

When the [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) function is called to obtain port configuration information, its *pInputData* parameter must be set with the address of a CONFIG_INFO_DATA_1 structure, and its *pOutputData* parameter must be set with the address of a [PORT_DATA_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/tcpxcv/ns-tcpxcv-_port_data_1) structure, which will be filled in when the function returns. Set this function's *pszDataName* parameter to the string L"GetConfigInfo".

See [TCPMON Xcv Interface](https://learn.microsoft.com/windows-hardware/drivers/print/tcpmon-xcv-interface) for more information.

## See also

[PORT_DATA_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/tcpxcv/ns-tcpxcv-_port_data_1)

[XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85))