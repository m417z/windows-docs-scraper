# NdisSetNblTimestampInfo function

## Description

Miniport drivers call **NdisSetNblTimestampInfo** to store a hardware or software timestamp in a [**NET\_BUFFER\_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) (NBL) structure.

## Parameters

### `Nbl` [_Inout_]

A pointer to a **NET_BUFFER_LIST** structure.

### `NblTimestamp` [_In_]

A pointer to an initialized [**NET_BUFFER_LIST_TIMESTAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/ns-nbltimestamp-net_buffer_list_timestamp) structure.

## Remarks

The miniport driver can store a software or hardware timestamp in an NBL's **NetBufferListInfo** array. The driver fills the **Timestamp** field of the [**NET_BUFFER_LIST_TIMESTAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/ns-nbltimestamp-net_buffer_list_timestamp) structure and calls **NdisSetNblTimestampInfo**, passing in the structure.

For more information on generating hardware and software timestamps, see [Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets).

## See also

[**NET_BUFFER_LIST_TIMESTAMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/ns-nbltimestamp-net_buffer_list_timestamp)

[**NET\_BUFFER\_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NdisGetNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndisgetnbltimestampinfo)

[**NdisCopyNblTimestampInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbltimestamp/nf-nbltimestamp-ndiscopynbltimestampinfo)

[Overview of NDIS packet timestamping](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-packet-timestamping)

[Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets)