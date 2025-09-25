# NdisFGetOptionalSwitchHandlers function

## Description

Hyper-V extensible switch extensions call the **NdisFGetOptionalSwitchHandlers** function to obtain a list of pointers to the Hyper-V extensible switch handler functions.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. When NDIS called the extension's [FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function, it passed this handle in the *NdisFilterHandle* parameter.

### `NdisSwitchContext` [out]

A pointer to the NDIS_SWITCH_CONTEXT value that identifies the extensible switch module to which the extension is attached. When the extension calls an extensible switch handler function, it must set the *NdisSwitchContext* parameter to the value of this handle.

### `NdisSwitchHandlers` [in, out]

A pointer to a caller-allocated [NDIS_SWITCH_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_optional_handlers) structure. If the call succeeds, this structure will contain a list of pointers to the extensible switch handler functions.

For more information about these handler functions, see [Hyper-V Extensible Switch Handler Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

**Note** Before the extension calls **NdisFGetOptionalSwitchHandlers**, it must initialize the **Header** member of the [NDIS_SWITCH_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_optional_handlers) structure.

## Return value

If the call succeeds, **NdisFGetOptionalSwitchHandlers** returns NDIS_STATUS_SUCCESS. Otherwise, it returns NDIS_STATUS_NOT_SUPPORTED if the extensible switch extension is not bound to the underlying extensible switch component.

## Remarks

The extension calls the **NdisFGetOptionalSwitchHandlers** function from its [FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

If the extension is installed with multiple **FilterMediaTypes** INF entries, the call to **NdisFGetOptionalSwitchHandlers** lets the extension determine whether it is bound and attached to the driver stack for either the extensible switch or a physical network adapter. If the call returns NDIS_STATUS_SUCCESS, the extension is attached within the extensible switch driver stack. If the call returns NDIS_STATUS_NOT_SUPPORTED, the extension is attached within the driver stack for a physical network adapter.

For more information about **FilterMediaTypes** INF entries for extensible switch extensions, see [INF Requirements for Hyper-V Extensible Switch Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/inf-requirements-for-hyper-v-extensions).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[NDIS_SWITCH_OPTIONAL_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_optional_handlers)