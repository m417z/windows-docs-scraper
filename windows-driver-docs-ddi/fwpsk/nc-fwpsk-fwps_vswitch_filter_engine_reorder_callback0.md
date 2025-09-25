# FWPS_VSWITCH_FILTER_ENGINE_REORDER_CALLBACK0 callback function

## Description

The filter engine calls the *vSwitchFilterEngineReorderNotifyRn* (*FWPS_VSWITCH_FILTER_ENGINE_REORDER_CALLBACK0*) callout function to notify the callout driver about events that are associated the virtual switch filter engine reordering.

**Note** *FWPS_VSWITCH_FILTER_ENGINE_REORDER_CALLBACK0* is a specific version of *FWPS_VSWITCH_FILTER_ENGINE_REORDER_CALLBACK*. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `notifyContext` [in, optional]

A pointer to a context provided by the callout driver. The driver passed this pointer to the *notifyContext* parameter of the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function. This parameter is optional and can be NULL.

### `completionContext` [in]

A pointer to a completion context provided by the callout driver. This parameter is optional and can be NULL.

### `isInRequiredPosition` [in]

A BOOLEAN value that is set to TRUE if the filter is in the required position in the filter stack or FALSE if it is not.

### `vSwitchExtensionLwfList` [in]

An [NDIS_ENUM_FILTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_enum_filters) structure that specifies a list of the virtual switch extension NDIS filter drivers.

## Return value

A callout's
*FWPS_VSWITCH_FILTER_ENGINE_REORDER_CALLBACK0* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout driver accepts the notification from the filter engine. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver registers a
*vSwitchFilterEngineReorderNotifyRn* function by calling
the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function.

By default, the WFP virtual switch extension is positioned as the first filtering extension at virtual switch ingress. (Therefore, it is also the last extension at virtual switch egress). This is usually the best position, because the WFP extension can intercept packets before any other extensions can modify them at ingress. Also, the WFP extension can intercept packets after all packet modifications are done at egress.

However, because an administrator can reorder any virtual switch extensions of the same class, the WFP extension can be reordered out of the default position. After a reorder occurs, a WFP client’s filters could be bypassed and might need to be adjusted.

If the *vSwitchFilterEngineReorderNotifyRn* callback is registered, the callout driver is notified when a virtual switch reorder is occurring. The callout driver receives an [NDIS_ENUM_FILTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_enum_filters) structure with an ordered list of current virtual switch extensions in the *vSwitchExtensionLwfList* parameter.

If the virtual switch extensions are reordered, the WFP extension is paused (see [FilterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause)) and restarted (see [FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)). From the WFP filter *FilterRestart* call, the WFP filter driver calls the [NdisEnumerateFilterModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisenumeratefiltermodules) function to obtain an ordered list of virtual switch extension filters. If the WFP extension is not in the default position, then the filter driver notifies the callout drivers.

A callout driver cannot return STATUS_PENDING from *vSwitchFilterEngineReorderNotifyRn*.

## See also

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[FilterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause)

[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)

[FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)

[FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0)

[NDIS_ENUM_FILTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_enum_filters)

[NdisEnumerateFilterModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisenumeratefiltermodules)

[NdisFRestartComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfrestartcomplete)