# ICertView2::SetTable

## Description

The **SetTable** method specifies which Certificate Services database table is used for subsequent calls to the methods of the [ICertView2](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview2) interface.

## Parameters

### `Table` [in]

Specifies the Certificate Services database table to use for subsequent calls. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **CVRC_TABLE_ATTRIBUTES** | The [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) table is used for subsequent calls. |
| **CVRC_TABLE_CRL** | The [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) table is used for subsequent calls. |
| **CVRC_TABLE_EXTENSIONS** | The extensions table is used for subsequent calls. |
| **CVRC_TABLE_REQCERT** | The table of pending requests, denied requests, issued certificates, and revoked certificates is used for subsequent calls. |

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Before calling the **SetTable** method, it is necessary to establish a connection with a Certificate Services server by calling the
[OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection) method first. After the **OpenConnection** and **SetTable** calls are made, subsequent calls to the [ICertView2](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview2) interface methods will use the Certificate Services database table specified by the **SetTable** method.

If the **SetTable** method is not called, then the default table CVRC_TABLE_REQCERT is used.

#### Examples

```cpp
HRESULT hr;

// Specify the certificate revocation list table.
hr = pCertView2->SetTable(CVRC_TABLE_CRL);
if (FAILED(hr))
{
    printf("Failed SetTable\n");
    exit(1);  // Or other error action.
}
```