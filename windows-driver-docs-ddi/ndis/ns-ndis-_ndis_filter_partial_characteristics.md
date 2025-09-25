# _NDIS_FILTER_PARTIAL_CHARACTERISTICS structure

## Description

To specify optional entry points for a filter module, a filter driver initializes an
NDIS_FILTER_PARTIAL_CHARACTERISTICS structure and passes it to the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
filter driver partial characteristics structure (NDIS_FILTER_PARTIAL_CHARACTERISTICS). Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_FILTER_PARTIAL_CHARACTERISTICS, the
**Revision** member to NDIS_FILTER_PARTIAL_CHARACTERISTICS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_FILTER_PARTIAL_CHARACTERISTICS_REVISION_1.

### `Flags`

Reserved for NDIS.

### `SendNetBufferListsHandler`

The entry point of the caller's
[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists) function. To bypass this function, set this member to **NULL**.

### `SendNetBufferListsCompleteHandler`

The entry point of the caller's
[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete) function. To bypass this function, set this member to
**NULL**.

### `CancelSendNetBufferListsHandler`

The entry point of the caller's
[FilterCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_send_net_buffer_lists) function. To bypass this function, set this member to **NULL**.

### `ReceiveNetBufferListsHandler`

The entry point of the caller's
[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists) function. To bypass this function, set this member to **NULL**.

### `ReturnNetBufferListsHandler`

The entry point of the caller's
[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists) function. To bypass this function, set this member to **NULL**.

## Remarks

This structure specifies optional
*FilterXxx* functions and other characteristics for a filter module. These characteristics override
the default values that the driver set in the
[NDIS_FILTER_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_driver_characteristics) structure that the driver passed to the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

## See also

[FilterCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_send_net_buffer_lists)

[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists)

[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists)

[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists)

[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete)

[NDIS_FILTER_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_driver_characteristics)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)