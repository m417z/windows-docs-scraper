# IStreamBufferConfigure2::GetMultiplexedPacketSize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetMultiplexedPacketSize** method returns the size of the multiplexed packets in the backing files for the Stream Buffer Engine.

## Parameters

### `pcbBytesPerPacket` [out]

Receives the packet size, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IStreamBufferConfigure2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure2)