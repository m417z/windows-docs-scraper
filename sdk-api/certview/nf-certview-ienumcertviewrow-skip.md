# IEnumCERTVIEWROW::Skip

## Description

The **Skip** method skips a specified number of rows in the
row enumeration sequence.

## Parameters

### `celt` [in]

The number of rows to skip. A positive value for the *celt* parameter causes the row-enumeration sequence to skip forward in the enumeration sequence. A negative value for the *celt* parameter causes the row enumeration sequence to skip backward in the enumeration sequence.

## Return value

### VB

If the method succeeds, the method returns S_OK.

A return value of E_INVALIDARG indicates that the *celt* parameter was set to a negative number which caused the row-enumeration sequence index to become less than zero.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Upon successful completion of this method, call the
**IEnumCERTVIEWROW::Skip** method to reference the current row in the row-enumeration sequence. After this second call is made, the
columns, attributes, and extensions associated with the certificate in the row can be enumerated using the methods of the following interfaces:

* [IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)
* [IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)
* [IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

The row-enumeration sequence maintains an internal zero-based index. The call to the **Skip** method causes this index to increase or decrease based on the setting of the *celt* parameter.

If a negative value of the *celt* parameter causes the index to be less than zero, the behavior of subsequent calls to [Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next) is undefined.

If a positive value of the *celt* parameter causes the index to exceed the last row in the enumeration sequence, a subsequent call to the [Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next) method will fail.

#### Examples

```cpp
// pEnumRow is previously instantiated pointer to IEnumCERTVIEWROW.
HRESULT  hr;
LONG     Index;
// Reposition the row enumerator to the beginning of the rows.
hr = pEnumRow->Reset();
if (FAILED(hr))
{
    printf("Unable to reset pEnumRow\n");
    goto error;
}
// Skip some rows.
hr = pEnumRow->Skip(5);
if (FAILED(hr))
{
    printf("Unable to skip rows\n");
    goto error;
}

// Get the next row.
hr = pEnumRow->Next(&Index);
if (S_OK == hr)
{
    // Use this row as needed.
}

error:

if (NULL != pEnumRow)
    pEnumRow->Release();
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

[IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow)

[IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next)

[IEnumCERTVIEWROW::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-reset)