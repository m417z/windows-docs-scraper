# NET_BUFFER_LIST_INFO macro

## Description

**NET_BUFFER_LIST_INFO** is a macro that NDIS drivers use to get and set information that applies to all the [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_Id`

An ID that indicates the type of information to access from the **NetBufferListInfo** member of the **NET_BUFFER_LIST** structure that the *\_NBL* parameter specifies.

## Return value

**NET_BUFFER_LIST_INFO** returns the information that is associated with the specified ID. The information is retrieved from the **NetBufferListInfo** member of the indicated **NET_BUFFER_LIST** structure.

## Remarks

For a list of the valid **NetBufferListInfo** IDs, see the [**NDIS_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblinfo/ne-nblinfo-ndis_net_buffer_list_info) enumeration reference page.

The following example demonstrates getting a **NetBufferListInfo** value:

```C++
value = NET_BUFFER_LIST_INFO(pNBL, Id);
```

The following example demonstrates setting a **NetBufferListInfo** value:

```C++
NET_BUFFER_LIST_INFO(pNBL, Id) = value;
```

## See also

[**NDIS_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblinfo/ne-nblinfo-ndis_net_buffer_list_info)

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)