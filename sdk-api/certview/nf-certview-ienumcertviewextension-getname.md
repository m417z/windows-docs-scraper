# IEnumCERTVIEWEXTENSION::GetName

## Description

The **GetName** method retrieves the name of the current extension in the extension-enumeration sequence.

 The returned extension name is an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) string, as in L"2.5.29.31".

## Parameters

### `pstrOut` [out]

A pointer to a value of **BSTR** type that contains the name of the extension.

## Return value

### C++

If the method succeeds, the method returns S_OK and tat the *pstrOut* parameter is set to the name of the extension.

To use this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and pass the address of this variable as *pstrOut*. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **String** that contains the name of the extension.

## Remarks

This function is used to retrieve the name of the extension currently referenced by the
extension-enumeration sequence.

If the extension-enumeration sequence is not referencing a valid extension, **GetName** will fail. Use one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWEXTENSION::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-reset): Moves to the next extension in the enumeration sequence.
* [IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next): Moves to the next extension in the enumeration sequence.
* [IEnumCERTVIEWEXTENSION::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-skip): Skips a specified number of extensions.

#### Examples

```cpp
BSTR  bstrExtName = NULL;

// pEnumExt is previously instantiated IEnumCERTVIEWEXTENSION object
hr = pEnumExt->GetName(&bstrExtName);
if (S_OK == hr)
    printf("Extension name is: %ws\n", bstrExtName);
else
    printf("GetName failed: %x\n", hr);

// free memory when done
if (NULL != bstrExtName)
    SysFreeString(bstrExtName);
```

## See also

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

[IEnumCERTVIEWEXTENSION::GetFlags](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getflags)

[IEnumCERTVIEWEXTENSION::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getvalue)

[IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next)

[IEnumCERTVIEWEXTENSION::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-reset)

[IEnumCERTVIEWEXTENSION::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-skip)