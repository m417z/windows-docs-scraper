# FwpsRedirectHandleDestroy0 function

## Description

The **FwpsRedirectHandleDestroy0** function destroys a redirect handle that was previously created by calling the [FwpsRedirectHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsredirecthandlecreate0) function.

**Note** **FwpsRedirectHandleDestroy0** is a specific version of **FwpsRedirectHandleDestroy**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `redirectHandle`

The redirect handle being destroyed.

## Remarks

 A callout driver calls the **FwpsRedirectHandleDestroy0** function to destroy a redirect handle that the callout driver previously created by calling the [FwpsRedirectHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsredirecthandlecreate0) function.

## See also

[FwpsRedirectHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsredirecthandlecreate0)