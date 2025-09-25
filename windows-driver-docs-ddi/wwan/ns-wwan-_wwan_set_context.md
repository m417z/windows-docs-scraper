# _WWAN_SET_CONTEXT structure

## Description

The WWAN_SET_CONTEXT structure represents a provisioned context with a network provider
identification that is supported by the MB device.

## Members

### `ContextId`

A unique ID for this context.

For
*set* OID_WWAN_PROVISIONED_CONTEXT requests, the MB Service can set the value to
WWAN_CONTEXT_ID_APPEND. If this value is used, the miniport driver should decide the index for storing
the context information. WWAN_CONTEXT_ID_APPEND should never be returned in response to
*query* OID_WWAN_PROVISIONED_CONTEXT requests.

### `ContextType`

Specifies the type of context being represented, for example, Internet connectivity, VPN (a
connection to a corporate network), or Voice-over-IP (VOIP). Miniport drivers should specify
**WwanContextTypeNone** for empty or unprovisioned contexts.

### `AccessString`

A NULL-terminated string to access the network. For GSM-based networks, this would be an Access
Point Name (APN) string such as "data.thephone-company.com". For CDMA-based networks, this might be a
special dial code such as "#777" or a Network Access Identifier (NAI) such as
"foo@thephone-company.com". This member can be **NULL**.

The size of the string should not exceed 100 bytes.

### `UserName`

The username to use for authentication. This member can be **NULL**.

### `Password`

The password to use for authentication. This member can be **NULL**.

### `Compression`

Specifies the compression to be used in the data connection for header and data. This member
applies only to GSM-based devices. The MB Service sets this member to
**WwanCompressionNone** for CDMA-based devices.

### `AuthType`

Authentication type to use for the PDP activation.

### `ProviderId`

A NULL-terminated string that represents the network provider identification for which the
provisioned context should be stored in
*set* OID_WWAN_PROVISIONED_CONTEXT requests. Miniport drivers should return the added provisioned
context in response to subsequent
*query* operations when a Subscriber Identity Module (SIM card) with this home provider ID is in the
device.