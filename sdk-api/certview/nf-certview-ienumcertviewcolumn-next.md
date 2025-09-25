# IEnumCERTVIEWCOLUMN::Next

## Description

The **Next** method moves to the next column in the column-enumeration sequence.

## Parameters

### `pIndex` [out]

A pointer to a variable that contains the index value of the next column referenced by the column-enumeration sequence. If there are no more columns to enumerate, this variable is set to –1. This method will fail if *pIndex* is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK and the next column in the column-enumeration sequence is now being referenced. If there are no more columns to enumerate, the method returns S_FALSE, and the *pIndex* parameter is set to a value of –1.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the index value of the column that is now referenced by the column-enumeration sequence. If there are no more columns to enumerate, the return value is –1.

## Remarks

Upon successful completion of this method, the information in the column can be obtained by calling one of the following methods:

* [IEnumCERTVIEWCOLUMN::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getname): Retrieves the nonlocalized name of the column.
* [IEnumCERTVIEWCOLUMN::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getdisplayname): Retrieves the localized name of the column.
* [IEnumCERTVIEWCOLUMN::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getvalue): Retrieves the data in the column.
* [IEnumCERTVIEWCOLUMN::GetType](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-gettype): Retrieves the type of data in the column.
* [IEnumCERTVIEWCOLUMN::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getmaxlength): Retrieves the maximum length, in bytes, of the column.

#### Examples

```cpp
LONG       nLength;
LONG       nType;
LONG       bIsindexed;
LONG       Index;

HRESULT    hr;

BSTR       bstrColName = NULL;

// pEnumCol is previously instantiated IEnumCERTVIEWCOLUMN object
// examine each column
while (S_OK == pEnumCol->Next(&Index))
{
    // determine database length
    hr = pEnumCol->GetMaxLength(&nLength);
    if (FAILED(hr))
    {
        printf("Failed GetMaxLength %x\n", hr);
        goto error;
    }

    // determine data type
    hr = pEnumCol->GetType(&nType);
    if (FAILED(hr))
    {
        printf("Failed GetType %x\n", hr);
        goto error;
    }

    // determine whether column is indexed
    hr = pEnumCol->IsIndexed(&bIsindexed);
    if (FAILED(hr))
    {
        printf("Failed IsIndexed %x\n", hr);
        goto error;
    }

    // retrieve column name
    hr = pEnumCol->GetName(&bstrColName);
    if (FAILED(hr))
    {
        printf("Failed GetName %x\n", hr);
        goto error;
    }

    // print this column's info on one line
    // print name and length
    printf("Column %ws has max length %d",
            bstrColName,
            nLength);

    // print data type
    switch (nType)
    {
        case PROPTYPE_BINARY:
            printf(" Type is Binary");
            break;
        case PROPTYPE_DATE:
            printf(" Type is Date+Time");
            break;
        case PROPTYPE_LONG:
            printf(" Type is Signed long");
            break;
        case PROPTYPE_STRING:
            printf(" Type is Unicode String");
            break;
        default:
            printf(" Type is unknown");
            break;
    }

    // print index status
    printf(bIsindexed ? " Indexed" : " Not indexed");
    // print new line marker
    printf("\n");

}

error:

// done processing, clear resources
if (NULL != bstrColName)
    SysFreeString(bstrColName);
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWCOLUMN::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getdisplayname)

[IEnumCERTVIEWCOLUMN::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getmaxlength)

[IEnumCERTVIEWCOLUMN::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getname)

[IEnumCERTVIEWCOLUMN::GetType](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-gettype)

[IEnumCERTVIEWCOLUMN::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getvalue)