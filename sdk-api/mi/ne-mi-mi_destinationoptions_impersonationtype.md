# MI_DestinationOptions_ImpersonationType enumeration

## Description

Used by the DCOM protocol handler to specify how impersonation is done on the server.

## Constants

### `MI_DestinationOptions_ImpersonationType_Default:0`

Use the default impersonation.

### `MI_DestinationOptions_ImpersonationType_None:1`

Do not impersonate.

### `MI_DestinationOptions_ImpersonationType_Identify:2`

Identify user only.

### `MI_DestinationOptions_ImpersonationType_Impersonate:3`

Allow impersonation of user.

### `MI_DestinationOptions_ImpersonationType_Delegate:4`

This option relates to Kerberos delegation and needs to be enabled on the domain.