# IMFSecureChannel::SetupSession

## Description

Passes the encrypted session key to the client.

## Parameters

### `pbEncryptedSessionKey` [in]

Pointer to a buffer that contains the encrypted session key. This parameter can be **NULL**.

### `cbSessionKey` [in]

Size of the *pbEncryptedSessionKey* buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFSecureChannel](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsecurechannel)