# IPSEC_SA_CONTEXT_SUBSCRIPTION0 structure

## Description

The **IPSEC_SA_CONTEXT_SUBSCRIPTION0** structure stores information used to subscribe to notifications about a particular IPsec security association (SA) context.

## Members

### `enumTemplate`

Type: **[IPSEC_SA_CONTEXT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_context_enum_template0)***

Enumeration template for limiting the subscription.

### `flags`

Type: **UINT32**

This member is reserved for system use.

### `sessionKey`

Type: **GUID**

Identifies the session that created the subscription.

## See also

[IPSEC_SA_CONTEXT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_context_enum_template0)