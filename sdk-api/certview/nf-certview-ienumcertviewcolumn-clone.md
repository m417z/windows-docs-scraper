# IEnumCERTVIEWCOLUMN::Clone

## Description

The **Clone** method creates a copy of the column-enumeration sequence.

## Parameters

### `ppenum` [out]

A pointer to a pointer of [IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn) type. This method will fail if the *ppenum* is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a cloned column-enumeration sequence object.

## Remarks

The column-enumeration sequence is obtained by a call to the [IEnumCERTVIEWROW::EnumCertViewColumn](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-enumcertviewcolumn) method.

#### Examples

```cpp
// pEnumCol is previously instantiated IEnumCERTVIEWCOLUMN object
IEnumCERTVIEWCOLUMN * pEnumCol2 = NULL;
HRESULT    hr;
hr = pEnumCol->Clone(&pEnumCol2);
if (S_OK != hr)
    printf("Unable to clone IEnumCERTVIEWCOLUMN\n");
else
{
    // use cloned object as needed
    // ...
    // done using cloned object, free memory
}
if (NULL != pEnumCol2)
    pEnumCol2->Release();
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWROW::EnumCertViewColumn](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-enumcertviewcolumn)