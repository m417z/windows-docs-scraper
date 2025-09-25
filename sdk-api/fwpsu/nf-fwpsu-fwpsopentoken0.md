## Description

Opens an access token.

> [!NOTE]
> **FwpsOpenToken0** is a specific version of **FwpsOpenToken**. For more info, see [WFP version-independent names and targeting specific versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows).

## Parameters

### `engineHandle`

A handle for an open session to the filter engine. A callout driver calls the FwpmEngineOpen0 function to open a session to the filter engine.

### `modifiedId`

Specifies an LUID that changes each time the token is modified. An application can use this value as a test of whether a security context has changed since it was last used.

### `desiredAccess`

ACCESS_MASK structure specifying the requested types of access to the access token. These requested access types are compared with the token's discretionary access-control list (DACL) to determine which accesses are granted or denied.

### `accessToken`

Pointer to a caller-allocated variable that receives a handle to the newly opened access token.

## Return value

The **FwpsOpenToken0** function returns one of the following NTSTATUS codes.

|Return code|Description|
|-|-|
|STATUS_SUCCESS|The access token was successfully opened.|
|Other status codes|An error occurred.|

## Remarks

## See also