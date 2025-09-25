# IIdentityProvider::Advise

## Description

The **Advise** method allows a calling application to specify the list of identity events for which the application is to be notified.

## Parameters

### `pIdentityAdvise` [in]

A pointer to the [IIdentityAdvise](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityadvise) interface implemented by the calling application. This interface provides a method that the identity provider can call when one of the events specified by the *dwIdentityUpdateEvents* parameter occurs.

### `dwIdentityUpdateEvents` [in]

The identity events for which the calling application is to be notified. The value of this parameter can be zero or more of the following values combined by using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **IDENTITY_ASSOCIATED**<br><br>0X0001 | An identity was associated with the identity provider. |
| **IDENTITY_DISASSOCIATED**<br><br>0X0002 | An identity was disassociated from the identity provider. |
| **IDENTITY_CREATED**<br><br>0X0004 | A new identity was created. |
| **IDENTITY_IMPORTED**<br><br>0X0008 | An identity was imported from another identity provider. |
| **IDENTITY_DELETED**<br><br>0X0010 | An identity was deleted from the identity store. |
| **IDENTITY_PROPCHANGE**<br><br>0X0020 | The value of a property of an identity changed. |

### `pdwCookie` [out]

A pointer to a value that identifies this connection. When you have finished using this connection, delete it by passing this value to the [UnAdvise](https://learn.microsoft.com/windows/desktop/api/identityprovider/nf-identityprovider-iidentityprovider-unadvise) method.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityAdvise::IdentityUpdated](https://learn.microsoft.com/windows/desktop/api/identityprovider/nf-identityprovider-iidentityadvise-identityupdated)

[IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider)