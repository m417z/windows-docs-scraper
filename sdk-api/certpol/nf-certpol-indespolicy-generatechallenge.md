# INDESPolicy::GenerateChallenge

## Description

Performs the policy decision whether to issue a challenge password to the SCEP client.

## Parameters

### `pwszTemplate` [in]

The template being requested for, as determined by NDES.

### `pwszParams` [in]

Parameters specific to the policy module implementation.

### `ppwszResponse` [out, retval]

After the user has been authenticated and authorized, the *ppwsxResponse* parameter contains the SCEP challenge password for the user. NDES will free this resource.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INDESPolicy](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-indespolicy)