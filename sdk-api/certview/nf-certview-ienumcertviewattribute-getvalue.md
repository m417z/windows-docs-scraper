# IEnumCERTVIEWATTRIBUTE::GetValue

## Description

The **GetValue** method retrieves the value of the current attribute in the attribute-enumeration sequence.

## Parameters

### `pstrOut` [out]

A pointer to a **BSTR** type that contains the value of the attribute.

## Return value

### C++

If the method succeeds, the method returns S_OK and the *pstrOut* is set to the value of the current attribute.

To use this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and pass the address of this variable as *pstrOut*. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **String** that represents the value of the current attribute.

## Remarks

This method is used to retrieve the data in the attribute currently referenced by the
attribute-enumeration sequence.

If the attribute-enumeration sequence is not referencing a valid attribute, **GetValue** will fail. Use
one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWATTRIBUTE::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWATTRIBUTE::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next): Moves to the next attribute in the enumeration sequence.
* [IEnumCERTVIEWATTRIBUTE::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-skip): Skips a specified number of attributes.

#### Examples

```cpp
BSTR    bstrAttribValue = NULL;

// pEnumAttr is previously instantiated IEnumCERTVIEWATTRIBUTE object
hr = pEnumAttr->GetValue(&bstrAttribValue);
if (S_OK != hr)
    printf("Failed call to GetValue - %x\n", hr);
else
    printf("Attribute value is %ws\n",bstrAttribValue);

// free memory when done
if (NULL != bstrAttribValue)
    SysFreeString(bstrAttribValue);
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)

[IEnumCERTVIEWATTRIBUTE::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getname)

[IEnumCERTVIEWATTRIBUTE::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next)

[IEnumCERTVIEWATTRIBUTE::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-reset)

[IEnumCERTVIEWATTRIBUTE::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-skip)