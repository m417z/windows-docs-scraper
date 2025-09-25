# INDESPolicy::Notify

## Description

Notifies the plug-in of the transaction status of the SCEP certificate request.

## Parameters

### `pwszChallenge` [in]

The authentication and authorization SCEP challenge password for the user.

### `pwszTransactionId` [in]

The SCEP request transaction ID.

### `disposition` [in]

The disposition of the transaction.

### `lastHResult` [in]

The **HRESULT** of the last operation.

### `pctbIssuedCertEncoded` [in]

The requested certificate, if issued.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INDESPolicy](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-indespolicy)