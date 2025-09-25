# NdisCopyNblTimestampInfo function

## Description

Miniport drivers call the **NdisCopyNblTimestampInfo** function to copy a software or hardware timestamp from a source [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure to a destination **NET_BUFFER_LIST** structure.

## Parameters

### `NblDest` [_Inout_]

A pointer to a destination [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

### `NblSrc` [_In_]

A pointer to the source **NET_BUFFER_LIST** structure where the miniport driver stored the timestamp.

## Remarks

Miniport drivers can use [**NdisSetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndissetnbltimestampinfo) and [**NdisGetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndisgetnbltimestampinfo) to set and retrieve timestamps.

For more information on generating hardware and software timestamps, see [Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets).

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NET_BUFFER_LIST_TIMESTAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/ns-nbltimestamp-net_buffer_list_timestamp)

[**NdisSetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndissetnbltimestampinfo)

[**NdisGetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndisgetnbltimestampinfo)

[Overview of NDIS packet timestamping](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-packet-timestamping)

[Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets)