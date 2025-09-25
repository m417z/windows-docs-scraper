# NdisFRestartFilter function

## Description

A filter driver calls the
**NdisFRestartFilter** function to request NDIS to initiate a restart operation for a filter
module.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

## Return value

**NdisFRestartFilter** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | [NdisFRestartFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfrestartfilter) returns NDIS_STATUS_SUCCESS if it started the restart operation. |
| **NDIS_STATUS_RESOURCES** | [NdisFRestartFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfrestartfilter) failed because of insufficient resources. |
| **NDIS_STATUS_FAILURE** | [NdisFRestartFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfrestartfilter) returns NDIS_STATUS_FAILURE if none of the preceding values applies. |

## Remarks

The filter driver can change the filter module attributes at run time by calling the
**NdisFRestartFilter** function.
**NdisFRestartFilter** schedules a pause and then a restart operation for the specified filter
module.

Before NDIS restarts the filter module, it calls the
[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options) function for the filter module. From
its *FilterSetModuleOptions* function, the filter driver can change the data handlers for that filter module by
calling the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function
and specifying a new set of handlers.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterSetModuleOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_set_module_options)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)