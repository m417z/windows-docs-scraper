# NdisFSetAttributes function

## Description

A filter driver calls the
**NdisFSetAttributes** function to specify a filter module context area.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `FilterModuleContext` [in]

The caller-allocated context area for this filter module.

### `FilterAttributes` [in]

A pointer to a filter driver allocated
[NDIS_FILTER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attributes) structure.

## Return value

**NdisFSetAttributes** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisFSetAttributes** returns NDIS_STATUS_SUCCESS if it set the filter driver attributes. |
| **NDIS_STATUS_RESOURCES** | **NdisFSetAttributes** failed because of insufficient resources. |
| **NDIS_STATUS_FAILURE** | **NdisFSetAttributes** returns NDIS_STATUS_FAILURE if none of the preceding values applies. |

## Remarks

A filter driver calls
**NdisFSetAttributes** from its
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function and passes the
handle that NDIS passed to
*FilterAttach* at the
*NdisFilterHandle* parameter. The
*FilterModuleContext* parameter of
**NdisFSetAttributes** specifies the context area for this filter module. NDIS passes the context area
back to the filter driver in calls to functions such as
[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists)

[NDIS_FILTER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attributes)