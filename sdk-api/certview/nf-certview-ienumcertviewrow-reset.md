# IEnumCERTVIEWROW::Reset

## Description

The **Reset** method moves to the beginning of the row-enumeration sequence.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Upon successful completion of this method, call the [IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next) method to reference the first row in the enumeration.

After this second call is made, the
columns, attributes, and extensions associated with the certificate in the row can be enumerated using the methods of the following interfaces:

* [IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)
* [IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)
* [IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

#### Examples

```cpp
// pEnumRow is previously instantiated pointer to IEnumCERTVIEWROW.
HRESULT hr;
LONG    Index;

// Ensure enumerator is at first row.
hr = pEnumRow->Reset();
if (FAILED(hr))
    printf("Failed to Reset\n");
else
{
    printf("Reset to beginning\n");
    // Retrieve first record.
    hr = pEnumRow->Next(&Index);
    // Examine hr for success and process row.
    // ...
}
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

[IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow)