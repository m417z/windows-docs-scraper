# DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3 callback function

## Description

**DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3** is called to change the overlay configuration being displayed.

## Parameters

### `hAdapter`

Identifies the adapter containing the overlay hardware.

### `pSetVidPnSourceAddressWithMultiPlaneOverlay`

A pointer to a [**DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddresswithmultiplaneoverlay3) structure that describes the surfaces and display options to present.

## Return value

**DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3** returns the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The routine completed successfully. |
| STATUS_INVALID_PARAMETER | In the [hardware flip queue model]/windows-hardware/drivers/display/hardware-flip-queue), the driver was unable to process a flip request. |
| STATUS_RETRY | Returned for reasons such as the driver failed to [queue a request to the hardware](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue) due to pending flips or the driver needs to be called at the PASSIVE_LEVEL. If the driver needs to be called at PASSIVE_LEVEL it should also set the [**DXGK_SETVIDPNSOURCEADDRESS_OUTPUT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_output_flags).**PrePresentNeeded** flag. |

## Remarks

This function is typically called at interrupt level, but if the driver needs to perform hardware configuration that can only be performed at PASSIVE_LEVEL, the driver can request that this function be recalled at PASSIVE_LEVEL by returning STATUS_RETRY and setting the [**DXGK_SETVIDPNSOURCEADDRESS_OUTPUT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_output_flags).**PrePresentNeeded** flag.

Even when called at PASSIVE_LEVEL, the driver should avoid spending a significant amount of time in this call because the call blocks the main GPU scheduler thread and delay could lead to present glitches. Time intensive actions should be queued as separate work items by driver and handled in background. In this scenario, any conflicts between the queued item and hardware changes demanded by future pre/post calls should be managed by the driver.

## See also

[**DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddresswithmultiplaneoverlay3)