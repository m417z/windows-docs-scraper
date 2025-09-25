# UAL_DATA_BLOB structure

## Description

Specifies information about a User Access Logging (UAL) session.

## Members

### `Size`

The size, in bytes, of this structure.

### `RoleGuid`

A [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that represents the role or minor product name associated with a UAL session.

### `TenantId`

A [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies a tenant of a hosted environment. This can be used to differentiate client tenants when more than one tenant uses the same host service.

### `Address`

The IP address of the client that accompanies the UAL payload from installed roles and products.

### `UserName`

The name of the client user that accompanies the UAL payload from installed roles and products..

## See also

[UalInstrument](https://learn.microsoft.com/previous-versions/windows/desktop/api/ual/nf-ual-ualinstrument)

[UalStart](https://learn.microsoft.com/previous-versions/windows/desktop/api/ual/nf-ual-ualstart)

[UalStop](https://learn.microsoft.com/previous-versions/windows/desktop/api/ual/nf-ual-ualstop)