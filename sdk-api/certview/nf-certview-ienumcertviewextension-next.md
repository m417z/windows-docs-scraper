# IEnumCERTVIEWEXTENSION::Next

## Description

The **Next** method moves to the next extension in the extension-enumeration sequence.

## Parameters

### `pIndex` [out]

A pointer to a variable that contains the index value of the next extension being referenced. If there are no more extensions to enumerate, this variable will be set to –1. This method fails if *pIndex* is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK and the next extension is now being referenced. If there are no more extensions, S_FALSE is returned, and the *pIndex* parameter is set to a value of –1.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the index value of the extension that is now referenced by the extension-enumeration sequence. If there are no more extensions to enumerate, the return value is –1.

## Remarks

Upon successful completion of this method, the extension name, flags, and value can be accessed through
the following methods:

* [IEnumCERTVIEWEXTENSION::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getname)
* [IEnumCERTVIEWEXTENSION::GetFlags](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getflags)
* [IEnumCERTVIEWEXTENSION::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getvalue)

#### Examples

```cpp
LONG  Index;
LONG  nCount;

// determine the number of extensions
nCount = 0;
// pEnumExt is previously instantiated IEnumCERTVIEWEXTENSION object
while (S_OK == pEnumExt->Next(&Index))
{
    nCount++;
}
printf("Number of extensions is %d\n", nCount);
```

## See also

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

[IEnumCERTVIEWEXTENSION::GetFlags](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getflags)

[IEnumCERTVIEWEXTENSION::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getname)

[IEnumCERTVIEWEXTENSION::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getvalue)