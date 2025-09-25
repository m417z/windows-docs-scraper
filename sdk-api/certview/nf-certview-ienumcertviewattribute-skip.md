# IEnumCERTVIEWATTRIBUTE::Skip

## Description

The **Skip** method skips a specified number of attributes in the attribute-enumeration sequence.

## Parameters

### `celt` [in]

The number of attributes to skip. A positive value for the *celt* parameter causes the attribute-enumeration sequence to skip forward in the sequence. A negative value for the *celt* parameter causes the attribute-enumeration sequence to skip backward in the sequence.

## Return value

### VB

If the method succeeds, the method returns S_OK.

A return value of E_INVALIDARG indicates that a negative value for the *celt* parameter caused the attribute-enumeration sequence index to become less than zero.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Upon successful completion of this method, call the
[IEnumCERTVIEWATTRIBUTE::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next) method to reference the current attribute in the attribute-enumeration sequence. The attribute name and value can be accessed through the
following methods:

* [IEnumCERTVIEWATTRIBUTE::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getname)
* [IEnumCERTVIEWATTRIBUTE::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getvalue)

The attribute-enumeration sequence maintains an internal zero-based index. The call to the [Skip](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute) method causes this index to increase or decrease by the number of attributes specified in the *celt* parameter.

If a negative value of the *celt* parameter causes the index to be less than zero, the behavior of subsequent calls to [IEnumCERTVIEWATTRIBUTE::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next) is undefined.

If a positive value of the *celt* parameter causes the index to exceed the last attribute in the enumeration sequence, a subsequent call to the [IEnumCERTVIEWATTRIBUTE::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next) method will fail.

#### Examples

```cpp
HRESULT  hr;
LONG     Index;

// pEnumAttr is previously instantiated IEnumCERTVIEWATTRIBUTE object
// skip the next 5 attributes
hr = pEnumAttr->Skip(5);
if (S_OK == hr)
{
    // get the next attribute
    hr = pEnumAttr->Next(&Index);
    if (S_OK == hr)
    {
        // Use this attribute as needed.
    }
}
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)

[IEnumCERTVIEWATTRIBUTE::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-reset)

[IEnumCERTVIEWATTRIBUTE:Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next)