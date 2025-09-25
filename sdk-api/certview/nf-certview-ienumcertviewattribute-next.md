# IEnumCERTVIEWATTRIBUTE::Next

## Description

The **Next** method moves to the next attribute in the attribute-enumeration sequence.

## Parameters

### `pIndex` [out]

A pointer to a variable that contains the index value of the next [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) being referenced. If there are no more attributes to enumerate, this variable is set to –1. This method fails if *pIndex* is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK and the next attribute is now being referenced by the attribute-enumeration sequence. If there are no more attributes, the method returns S_FALSE, and *pIndex* is set to a value of –1.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the index value of the attribute that is now referenced by the attribute-enumeration sequence. If there are no more attributes to enumerate, the return value is –1.

## Remarks

Upon successful completion of this method, the attribute name and value can be accessed through the
following methods:

* [IEnumCERTVIEWATTRIBUTE::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getname)
* [IEnumCERTVIEWATTRIBUTE::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getvalue)

#### Examples

```cpp
LONG       Index;
HRESULT    hr;
BSTR       bstrAttribName = NULL;

// pEnumAttr is previously instantiated IEnumCERTVIEWATTRIBUTE object
while (S_OK == pEnumAttr->Next(&Index))
{
    // retrieve the attribute name
    hr = pEnumAttr->GetName(&bstrAttribName);
    if (FAILED(hr))
        printf("Failed GetName -  %x\n", hr );
    else
        printf("Attribute name: %ws\n", bstrAttribName);
}

// Free resources.
if (NULL != bstrAttribName)
    SysFreeString(bstrAttribName);
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)

[IEnumCERTVIEWATTRIBUTE::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getname)

[IEnumCERTVIEWATTRIBUTE::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getvalue)

[IEnumCERTVIEWATTRIBUTE::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-reset)

[IEnumCERTVIEWATTRIBUTE::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-skip)