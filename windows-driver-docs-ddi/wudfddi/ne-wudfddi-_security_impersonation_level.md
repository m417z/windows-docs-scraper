# _SECURITY_IMPERSONATION_LEVEL enumeration (wudfddi.h)

## Description

[Applies to UMDF only]

The **SECURITY_IMPERSONATION_LEVEL** enumeration contains values that identify security impersonation levels.

## Constants

### `SecurityAnonymous`

The driver cannot impersonate or identify the client.

### `SecurityIdentification`

The driver can obtain the identity and privileges of the client but cannot impersonate the client.

### `SecurityImpersonation`

The driver can impersonate the client's security context on the local system.

### `SecurityDelegation`

The driver can impersonate the client's security context on remote systems.

## Remarks

For more information about impersonation in the UMDF, see [Handling Client Impersonation](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers).

A UMDF driver supplies one of the values of **SECURITY_IMPERSONATION_LEVEL** to the [IWDFIoRequest::Impersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-impersonate) method to set the security impersonation level.

For more information about the security impersonation levels, see the **SECURITY_IMPERSONATION_LEVEL** enumeration type in the Microsoft Windows SDK documentation.

## See also

[IWDFIoRequest::Impersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-impersonate)