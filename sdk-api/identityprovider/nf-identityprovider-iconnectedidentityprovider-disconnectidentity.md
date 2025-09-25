# IConnectedIdentityProvider::DisconnectIdentity

## Description

Disconnects an online identity from the current domain user.

## Return value

If the method succeeds, the method returns S_OK.

If the method fails, the method returns a Win32 error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ERROR_NO_SUCH_USER** | The domain user is not connected to an online identity. |

## See also

[IConnectedIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iconnectedidentityprovider)