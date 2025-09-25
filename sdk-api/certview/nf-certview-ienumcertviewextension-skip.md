# IEnumCERTVIEWEXTENSION::Skip

## Description

The **Skip** method skips a specified number of extensions in the extension-enumeration sequence.

## Parameters

### `celt` [in]

The number of extensions to skip. A positive value for the *celt* parameter causes the extension-enumeration sequence to skip forward in the sequence. A negative value for the *celt* parameter causes the extension-enumeration sequence to skip backward in the sequence.

## Return value

### VB

If the method succeeds, the method returns S_OK.

A return value of E_INVALIDARG indicates that a negative value for the *celt* parameter caused the extension-enumeration sequence index to become less than zero.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Upon successful completion of this method, call the
[IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next) method to reference the current extension in the extension-enumeration sequence. The extension name, flags, and value can be accessed through
the following methods:

* [IEnumCERTVIEWEXTENSION::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getname)
* [IEnumCERTVIEWEXTENSION::GetFlags](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getflags)
* [IEnumCERTVIEWEXTENSION::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getvalue)

The extension-enumeration sequence maintains an internal zero-based index. The call to the **Skip** method causes this index to increase or decrease by the number of extensions specified in the *celt* parameter.

If a negative value of the *celt* parameter causes the index to be less than zero, the behavior of subsequent calls to [IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next) is undefined.

If a positive value of the *celt* parameter causes the index to exceed the last extension in the enumeration sequence, a subsequent call to the [IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next) method will fail.

#### Examples

```cpp
HRESULT  hr;
LONG     Index;

// pEnumExt is previously instantiated IEnumCERTVIEWEXTENSION object
// skip the next 5 extensions
hr = pEnumExt->Skip(5);
if (S_OK == hr)
{
    // get the next extension
    hr = pEnumExt->Next(&Index);
    if (S_OK == hr)
    {
        // Use this extension as needed.
    }
}
```

## See also

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

[IEnumCERTVIEWEXTENSION::GetFlags](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getflags)

[IEnumCERTVIEWEXTENSION::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getname)

[IEnumCERTVIEWEXTENSION::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getvalue)

[IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next)