# ICertView::OpenView

## Description

The **OpenView** method opens a view to a Certificate Services database and instantiates an instance of an [IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow) object.

## Parameters

### `ppenum` [out]

A pointer to a pointer of [IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow) type.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is an [IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow) object.

## Remarks

Before calling the **OpenView** method, it is necessary to establish a connection with a Certificate Services server by calling the
[OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection) method first.

The
[IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow) object returned by this call represents a row-enumeration sequence whose internal index is pointing to the beginning of the sequence. To look at the first row in the sequence, call the
[IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next) method, which moves the internal index to the first row.

To view a nondefault column set or a subset of the rows, call
[SetResultColumnCount](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setresultcolumncount),
[SetResultColumn](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setresultcolumn), and
[SetRestriction](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-setrestriction) after calling [OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection) and before calling **OpenView**.

#### Examples

```cpp
// pCertView is previously instantiated pointer to ICertView.
IEnumCERTVIEWROW * pEnumRow = NULL;
HRESULT    hr;

hr = pCertView->OpenView(&pEnumRow);
if (S_OK != hr)
    printf("Failed ICertView::OpenView - %x\n", hr);
else
    // use pEnumRow as needed, to enumerate data rows
    // ...
// Done processing, free resources.
if (NULL != pEnumRow)
    pEnumRow->Release();
```

## See also

[ICertView](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview)

[ICertView2](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-icertview2)

[ICertView::OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection)

[IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow)

[IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next)