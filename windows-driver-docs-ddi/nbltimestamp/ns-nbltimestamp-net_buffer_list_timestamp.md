# _NET_BUFFER_LIST_TIMESTAMP structure

## Description

The **NET_BUFFER_LIST_TIMESTAMP** structure represents a software or hardware timestamp that is generated on reception or transmission of a packet.

## Members

### `Timestamp`

A 64-bit integer value that represents a software or hardware timestamp.

## Remarks

Miniport drivers can store a timestamp in the [**NET\_BUFFER\_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) (NBL) structure's **NetBufferListInfo** array. Drivers can use the **NET_BUFFER_LIST_TIMESTAMP** structure to set the timestamp in the NBL's **NetBufferListInfo** field. The driver fills the **Timestamp** field of the **NET_BUFFER_LIST_TIMESTAMP** structure and calls [**NdisSetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndissetnbltimestampinfo), passing in the structure.

Miniport drivers can use [**NdisGetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndisgetnbltimestampinfo) and [**NdisCopyNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndiscopynbltimestampinfo) to retrieve and copy timestamps.

For more information on generating hardware and software timestamps, see [Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets).

## See also

[**NdisSetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndissetnbltimestampinfo)

[**NdisGetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndisgetnbltimestampinfo)

[**NdisCopyNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndiscopynbltimestampinfo)

[Overview of NDIS packet timestamping](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-packet-timestamping)

[Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets)