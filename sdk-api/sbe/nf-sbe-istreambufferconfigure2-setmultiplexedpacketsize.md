# IStreamBufferConfigure2::SetMultiplexedPacketSize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetMultiplexedPacketSize** method sets the size of the multiplexed packets in the backing files for the Stream Buffer Engine.

## Parameters

### `cbBytesPerPacket` [in]

Specifies the packet size, in bytes. The value must be between 8192 and 65535, inclusive. The default value is 65535.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For low-bit-rate streams, the default packet size may be unnecessarily large. You can use this method to reduce the packet size.

## See also

[IStreamBufferConfigure2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure2)