# IX509PrivateKey::get_UniqueContainerName

## Description

The **UniqueContainerName** property retrieves a unique name for the key container.

This property is read-only.

## Parameters

## Remarks

This property retrieves an alternate name that can be used when accessing a key when you believe that the [ContainerName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_containername) property value is not unique enough to provide adequate identification. Typically the key container creates the name. For example, the Cryptography API: Next Generation (CNG) key storage provider (KSP) returns the name of the encrypted file that contains the key.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)