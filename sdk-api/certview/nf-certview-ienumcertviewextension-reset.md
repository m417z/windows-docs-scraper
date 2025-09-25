# IEnumCERTVIEWEXTENSION::Reset

## Description

The **Reset** method moves to the beginning of the extension-enumeration sequence.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Upon successful completion of this method, call the
[IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next) method to reference the first extension in the extension-enumeration sequence.

The extension name, flags, and value can be accessed through
the following methods:

* [IEnumCERTVIEWEXTENSION::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getname)
* [IEnumCERTVIEWEXTENSION::GetFlags](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getflags)
* [IEnumCERTVIEWEXTENSION::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getvalue)

#### Examples

```cpp
HRESULT  hr;
LONG     Index;

// pEnumExt is previously instantiated IEnumCERTVIEWEXTENSION object
hr = pEnumExt->Reset();
if (S_OK != hr)
    printf("Unable to reset pEnumExt - %x\n", hr);
    // call appropriate error handler / exit routine
else
{
    // reset to beginning of extensions again
    while (S_OK == pEnumExt->Next(&Index))
    {
        // Use each extension as needed.
    }
}
```

## See also

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

[IEnumCERTVIEWEXTENSION::GetFlags](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getflags)

[IEnumCERTVIEWEXTENSION::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getname)

[IEnumCERTVIEWEXTENSION::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getvalue)

[IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next)