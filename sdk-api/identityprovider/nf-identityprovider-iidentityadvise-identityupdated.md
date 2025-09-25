# IIdentityAdvise::IdentityUpdated

## Description

The **IdentityUpdated** method is called by an identity provider to notify a calling application that an identity event occurred. An application calls the [IIdentityProvider::Advise](https://learn.microsoft.com/windows/desktop/api/identityprovider/nf-identityprovider-iidentityprovider-advise) method to specify events for which it is to be notified.

## Parameters

### `dwIdentityUpdateEvents` [in]

The identity events that occurred. The value of this parameter can be zero or more of the following values combined by using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **IDENTITY_ASSOCIATED**<br><br>0X0001 | An identity was associated with the identity provider. |
| **IDENTITY_DISASSOCIATED**<br><br>0X0002 | An identity was disassociated from the identity provider. |
| **IDENTITY_CREATED**<br><br>0X0004 | A new identity was created. |
| **IDENTITY_IMPORTED**<br><br>0X0008 | An identity was imported from another identity provider. |
| **IDENTITY_DELETED**<br><br>0X0010 | An identity was deleted from the identity store. |
| **IDENTITY_PROPCHANGE**<br><br>0X0020 | The value of a property of an identity changed. |
| **IDENTITY_CONNECTED**<br><br>0X0040 | The identity is a connected identity. |
| **IDENTITY_DISCONNECTED**<br><br>0X0080 | The identity was disconnected from the identity provider. |

### `lpszUniqueID` [in]

The identity associated with the events that occurred.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityAdvise](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityadvise)