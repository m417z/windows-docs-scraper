# ICertView::SetResultColumnCount

## Description

The **SetResultColumnCount** method specifies the maximum number of columns for the result set of a customized view of the Certificate Services database.

## Parameters

### `cResultColumn` [in]

Specifies the maximum number of columns in the result set. This parameter can be set to a positive number, or to zero if you are only interested in counting the rows of the Certificate Services database, or to one of the following constants.

| Value | Meaning |
| --- | --- |
| **CV_COLUMN_LOG_DEFAULT** | The number of columns in the result set will be the number of columns in the Certificate Services' default result set for requests that have been resolved. A request is resolved if it has resulted in an issued certificate or a failed request; revoked certificates are considered resolved. |
| **CV_COLUMN_LOG_FAILED_DEFAULT** | The number of columns in the result set will be the number of columns in the Certificate Services' default result set for requests that have failed. |
| **CV_COLUMN_QUEUE_DEFAULT** | The number of columns in the result set will be the number of columns in the Certificate Services' default result set for requests that have not been resolved. |

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Before calling the **SetResultColumnCount** method, it is necessary to establish a connection with a Certificate Services server by calling the
[OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection) method first. After the connection is established, this method can be called once, and only once, to specify the maximum number of columns in the result set.

If the *cResultColumn* parameter is set to a positive number (not one of the predefined constants), the
[SetResultColumn](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setresultcolumn) method must be called to specify which columns to include in the result set. Note that **SetResultColumn** fails if it is called more than the number of columns specified by **SetResultColumnCount**.

#### Examples

```cpp
HRESULT    hr;
// Specify the result set for logged requests.
// pCertView is pointer to ICertView (which has an Open Connection)
hr = pCertView->SetResultColumnCount(CV_COLUMN_LOG_DEFAULT);
if (S_OK != hr)
    printf("Failed ICertView::SetResultColumnCount - %x\n", hr);
else
{
    // Retrieve data rows by means of ICertView::OpenView.
    // ...
}
```

## See also

[ICertView](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview)

[ICertView2](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview2)

[ICertView::OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection)

[ICertView::SetRestriction](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setrestriction)

[ICertView::SetResultColumn](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setresultcolumn)