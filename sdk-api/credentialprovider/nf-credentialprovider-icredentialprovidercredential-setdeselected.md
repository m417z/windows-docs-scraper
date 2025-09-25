# ICredentialProviderCredential::SetDeselected

## Description

Called when a credential loses selection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Credential providers should use this method to purge all buffers containing sensitive information such as a password or Personal Identification Number (PIN). This is in addition to purging them in the destructor of the class that stores them.