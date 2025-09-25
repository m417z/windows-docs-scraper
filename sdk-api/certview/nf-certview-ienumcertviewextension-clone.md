# IEnumCERTVIEWEXTENSION::Clone

## Description

The [Clone](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension) method creates a copy of the extension-enumeration sequence.

## Parameters

### `ppenum` [out]

A pointer to a pointer of [IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension) type. This method will fail if the *ppenum* parameter is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a cloned extension-enumeration sequence object.

## Remarks

The extension-enumeration sequence object is obtained by a call to the [IEnumCERTVIEWROW::EnumCertViewExtension](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-enumcertviewextension) method.

#### Examples

```cpp
IEnumCERTVIEWEXTENSION * pEnumExt2 = NULL;
HRESULT                  hr;

// pEnumExt is previously instantiated IEnumCERTVIEWEXTENSION object
hr = pEnumExt->Clone(&pEnumExt2);
if (S_OK != hr)
    printf("Unable to clone IEnumCERTVIEWEXTENSION\n");
else
{
    // use cloned object as needed
    //...
}
// done using cloned object, free memory
if (NULL != pEnumExt2)
    pEnumExt2->Release();
```

## See also

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)