# IEnumCERTVIEWATTRIBUTE::Clone

## Description

The **Clone** method creates a copy of the attribute-enumeration sequence object in its current state.

## Parameters

### `ppenum` [out]

A pointer to a pointer of [IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute) type. This function will fail if *ppenum* is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a cloned attribute-enumeration sequence object.

## Remarks

The attribute-enumeration sequence object is obtained by a call to
the [IEnumCERTVIEWROW::EnumCertViewAttribute](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-enumcertviewattribute) method.

#### Examples

```cpp
// pEnumAttr is previously instantiated IEnumCERTVIEWATTRIBUTE object
IEnumCERTVIEWATTRIBUTE * pEnumAttr2 = NULL;
HRESULT    hr;
hr = pEnumAttr->Clone(&pEnumAttr2);
if (S_OK != hr)
    printf("Unable to clone IEnumCERTVIEWATTRIBUTE\n");
else
{
    // use cloned object as needed
    // ...
}
// done using cloned object, free memory
if (NULL != pEnumAttr2)
    pEnumAttr2->Release();
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)