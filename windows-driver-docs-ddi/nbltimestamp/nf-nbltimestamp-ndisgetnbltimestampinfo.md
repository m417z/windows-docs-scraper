# NdisGetNblTimestampInfo function

## Description

Miniport drivers call **NdisGetNblTimestampInfo** to retrieve a hardware or software timestamp stored in a [**NET\_BUFFER\_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) (NBL) structure.

## Parameters

### `Nbl` [_In_]

A pointer to the NBL where the miniport stored the timestamp.

### `NblTimestamp` [_Out_]

A pointer to a [**NET_BUFFER_LIST_TIMESTAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/ns-nbltimestamp-net_buffer_list_timestamp) structure. When this function returns, this member contains the timestamp that the miniport stored in the NBL.

## Remarks

Miniport drivers can use [**NdisSetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndissetnbltimestampinfo) and [**NdisCopyNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndiscopynbltimestampinfo) to set and copy timestamps.

For more information on generating hardware and software timestamps, see [Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets).

## See also

[**NET_BUFFER_LIST_TIMESTAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/ns-nbltimestamp-net_buffer_list_timestamp)

[**NdisSetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndissetnbltimestampinfo)

[**NdisCopyNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndiscopynbltimestampinfo)

[Overview of NDIS packet timestamping](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-packet-timestamping)

[Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets)