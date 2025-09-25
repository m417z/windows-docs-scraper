## Description

**NET_BUFFER_LIST_CONTEXT_DATA_START** is a macro that NDIS drivers use to get a pointer to the [**NET_BUFFER_LIST_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) context space that is associated with a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Syntax

```cpp
#define NET_BUFFER_LIST_CONTEXT_DATA_START(_NBL) ((PUCHAR)(((_NBL)->Context)+1)+(_NBL)->Context->Offset)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_CONTEXT_DATA_START** returns a pointer to the **NET_BUFFER_LIST_CONTEXT** context space that is associated with the indicated [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

**NET_BUFFER_LIST_CONTEXT_DATA_START** returns a pointer to the start of the *used context space* in the **ContextData** member of the [**NET_BUFFER_LIST_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NET_BUFFER_LIST_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)