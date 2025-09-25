# IMFASFMultiplexer::GetStatistics

## Description

Retrieves multiplexer statistics.

## Parameters

### `wStreamNumber` [in]

The stream number for which to obtain statistics.

### `pMuxStats` [out]

Pointer to an [ASF_MUX_STATISTICS](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ns-wmcontainer-asf_mux_statistics) structure that receives the statistics.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[Generating New ASF Data Packets](https://learn.microsoft.com/windows/desktop/medfound/generating-new-asf-data-packets)

[IMFASFMultiplexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmultiplexer)