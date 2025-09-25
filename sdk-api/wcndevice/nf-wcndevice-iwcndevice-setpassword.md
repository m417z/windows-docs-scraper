# IWCNDevice::SetPassword

## Description

The **IWCNDevice::SetPassword** method configures the authentication method value, and if required, a password used for the pending session. This method may only be called prior to [IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect).

## Parameters

### `Type` [in]

A **WCN_PASSWORD_TYPE** value that specifies the authentication method used for the session.

| Value | Meaning |
| --- | --- |
| **WCN_PASSWORD_TYPE_PUSH_BUTTON** | Use PushButton authentication. The value of *dwPasswordLength* must be **NULL**. |
| **WCN_PASSWORD_TYPE_PIN** | Use PIN-based authentication. |

### `dwPasswordLength` [in]

Number of bytes in the buffer *pbPassword*.

### `pbPassword` [in]

A byte array of the password, encoded in ASCII.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The password will be used for the pending session. |
| **E_INVALIDARG** | The password type is WCN_PASSWORD_TYPE_PUSH_BUTTON and the password length is not zero.<br><br>The password type is not WCN_PASSWORD_TYPE_PUSH_BUTTON or WCN_PASSWORD_TYPE_PIN. |

## Remarks

The byte array is not **NULL**-terminated. For example, if the password is a 4-digit PIN, you should pass dwPasswordLength as 4 and pbPassword should point to a 4-byte array containing the PIN in ASCII.

## See also

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)

[IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect)

**WCN_PASSWORD_TYPE**