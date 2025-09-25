# PNRP_CLOUD_ID structure

## Description

The **PNRP_CLOUD_ID** structure contains the values that define a network cloud.

## Members

### `AddressFamily`

Must be AF_INET6.

### `Scope`

Specifies the scope of the cloud. Use one of the following values:

| Value | Description |
| --- | --- |
| PNRP_SCOPE_ANY | The cloud can be in any scope. |
| PNRP_GLOBAL_SCOPE | The cloud must be a global scope. |
| PNRP_SITE_LOCAL_SCOPE | The cloud must be a site-local scope. |
| PNRP_LINK_LOCAL_SCOPE | The cloud must be a link-local scope. |

### `ScopeId`

Specifies the ID for this scope.

## See also

[PNRPCLOUDINFO](https://learn.microsoft.com/windows/desktop/api/pnrpns/ns-pnrpns-pnrpcloudinfo)