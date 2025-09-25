# FwpsRedirectHandleCreate0 function

## Description

The **FwpsRedirectHandleCreate0** function creates a handle that connection redirection functions can use to redirect connections to a local process. For more information about redirection, see [Using Bind or Connect Redirection](https://learn.microsoft.com/windows-hardware/drivers/network/using-bind-or-connect-redirection).

**Note** **FwpsRedirectHandleCreate0** is a specific version of **FwpsRedirectHandleCreate**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `providerGuid`

The provider GUID.

### `flags`

Reserved. Set to zero.

### `redirectHandle`

A pointer to the variable that receives the handle.

## Return value

The
**FwpsRedirectHandleCreate0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A redirect handle was successfully returned. The variable that the *redirectHandle* parameter points to contains the handle. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the **FwpsRedirectHandleCreate0** function to create a handle that can be used to redirect connections.

For more information about redirection, see [Using Bind or Connect Redirection](https://learn.microsoft.com/windows-hardware/drivers/network/using-bind-or-connect-redirection).

Your callout driver should call **FwpsRedirectHandleCreate0** once and cache the handle so that it can reuse the handle.

Before an Application Layer Enforcement (ALE) connect redirection callout can redirect connections to a local process, it must obtain a redirect handle with the **FwpsRedirectHandleCreate0** function and put the handle in the [FWPS_CONNECT_REQUEST0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-_fwps_connect_request0) structure. The callout modifies the structure in the [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) for the ALE connect redirect layers.

After a callout driver has finished using a redirect handle, it must call the [FwpsRedirectHandleDestroy0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsredirecthandledestroy0) function to destroy the handle.

## See also

[FWPS_CONNECT_REQUEST0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-_fwps_connect_request0)

[FwpsRedirectHandleDestroy0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsredirecthandledestroy0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)