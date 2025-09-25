## Description

Retrieves security information about the application layer enforcement (ALE) endpoint enumeration session.

> [!NOTE]
> **FwpsAleEndpointGetSecurityInfo0** is a specific version of **FwpsAleEndpointGetSecurityInfo**. For more info, see [WFP version-independent names and targeting specific versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows).

## Parameters

### `engineHandle`

A handle for an open session with the filter engine. This handle is obtained when a session is opened by calling FwpmEngineOpen0.

### `securityInfo`

A set of security information flags. For more information, see the SECURITY_INFORMATION description in the Installable File Systems driver documentation.

### `sidOwner`

The security identifier of the security owner.

### `sidGroup`

The security identifier of the security group.

### `dacl`

The discretionary access control list.

### `sacl`

The system access control list.

### `securityDescriptor`

The security descriptor structure.

## Return value

The **FwpsAleEndpointGetSecurityInfo0** function returns one of the following NTSTATUS codes.

|Return code|Description|
|-|-|
|STATUS_SUCCESS|The function succeeded.|
|Other status codes|An error occurred.|

## Remarks

## See also