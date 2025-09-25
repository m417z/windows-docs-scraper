# IEnumCERTVIEWATTRIBUTE::GetName

## Description

The **GetName** method retrieves the name of the current attribute in the attribute-enumeration sequence.

## Parameters

### `pstrOut` [out]

A pointer to a variable of **BSTR** type that contains the name of the attribute.

## Return value

### C++

If the method succeeds, the method returns S_OK and the *pstrOut* parameter contains the name of the [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

To use this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and pass the address of this variable as *pstrOut*. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **String** that contains the name of the attribute.

## Remarks

This method is used to retrieve the name of the attribute currently referenced by the
attribute-enumeration sequence.

If the attribute-enumeration sequence is not referencing a valid attribute, **GetName** will fail. Use one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWATTRIBUTE::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWATTRIBUTE::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next): Moves to the next attribute in the enumeration sequence.
* [IEnumCERTVIEWATTRIBUTE::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-skip): Skips a specified number of attributes.

#### Examples

```cpp
BSTR    bstrAttribName = NULL;

// pEnumAttr is previously instantiated IEnumCERTVIEWATTRIBUTE object
hr = pEnumAttr->GetName(&bstrAttribName);
if (S_OK != hr)
    printf("Failed call to GetName - %x\n", hr);
else
    printf("Attribute name is %ws\n", bstrAttribName );

// free memory when done
if (NULL != bstrAttribName)
    SysFreeString(bstrAttribName);
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)

[IEnumCERTVIEWATTRIBUTE::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getvalue)

[IEnumCERTVIEWATTRIBUTE::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next)

[IEnumCERTVIEWATTRIBUTE::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-reset)

[IEnumCERTVIEWATTRIBUTE::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-skip)