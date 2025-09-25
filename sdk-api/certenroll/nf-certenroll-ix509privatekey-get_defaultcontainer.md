# IX509PrivateKey::get_DefaultContainer

## Description

The **DefaultContainer** property retrieves a Boolean value that specifies whether the private key represents the default key container.

This property is read-only.

## Parameters

## Remarks

Key containers are identified by name. The name can be specified by the client, or it can be a default value supported by the CSP or KSP. For example, some CSPs use the logon name of the current user as the default container name.

This property value is set when the [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-open) or [Create](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-create) methods are called.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)