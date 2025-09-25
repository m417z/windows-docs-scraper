# IDARG_IN_ADAPTERSETRENDERADAPTER structure

## Description

The **IDARG_IN_ADAPTERSETRENDERADAPTER** structure identifies the render adapter that the driver wants to be used to render the desktop image for the swapchains on this adapter.

## Members

### `PreferredRenderAdapter`

Locally unique identifier (LUID) that identifies the driver's preferred adapter. Setting a value of {0, 0} indicates that the driver has no preference for the render adapter used.

## Remarks

The driver's specified adapter is a preference and the OS might decide to use a different render adapter. For example, if the specified adapter has been PnpStopped then the OS will pick an alternative.

## See also

[**IddCxAdapterSetRenderAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadaptersetrenderadapter)

[**PFN_IDDCXADAPTERSETRENDERADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-pfn_iddcxadaptersetrenderadapter)