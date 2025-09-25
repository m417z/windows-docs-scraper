# FwpsOpenToken0 function

## Description

The **FwpsOpenToken0** function opens an access token.

**Note** **FwpsOpenToken0** is a specific version of **FwpsOpenToken**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `engineHandle` [in]

A handle for an open session to the filter engine. A callout driver calls the
[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0) function to open a
session to the filter engine.

### `modifiedId` [in]

Specifies an [LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid) that changes each time the token is modified. An application can use this value as a test of whether a security context has changed since it was last used.

### `desiredAccess` [in]

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) structure specifying the requested types of access to the access token. These requested access types are compared with the token's discretionary access-control list (**DACL**) to determine which accesses are granted or denied.

### `accessToken` [out]

Pointer to a caller-allocated variable that receives a handle to the newly opened access token.

## Return value

The
**FwpsOpenToken0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The access token was successfully opened. |
| **Other status codes** | An error occurred. |

## Remarks
The process that calls **fwpsopentoken0** must have the SE_DEBUG_NAME privilege enabled in its process token.

## See also

[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)