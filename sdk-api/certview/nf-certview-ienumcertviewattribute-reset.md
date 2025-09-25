# IEnumCERTVIEWATTRIBUTE::Reset

## Description

The **Reset** method moves to the beginning of the attribute-enumeration sequence.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Upon successful completion of this method, call the
[IEnumCERTVIEWATTRIBUTE::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next) method to reference the first attribute in the attribute-enumeration sequence. The attribute name and value can be accessed by using the
following methods:

* [IEnumCERTVIEWATTRIBUTE::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getname)
* [IEnumCERTVIEWATTRIBUTE::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getvalue)

#### Examples

```cpp
// pEnumAttr is a previously instantiated
// IEnumCERTVIEWATTRIBUTE object.
HRESULT  hr;
LONG     Index;

hr = pEnumAttr->Reset();
if (S_OK != hr)
    printf("Unable to reset pEnumAttr - %x\n", hr );

    // Call the appropriate error handler and exit routine.
else
{

    // Reset to the beginning of the attributes again.
    while (S_OK == pEnumAttr->Next(&Index))
    {

        // Use each attribute as needed.
    }
}
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)

[IEnumCERTVIEWATTRIBUTE::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getname)

[IEnumCERTVIEWATTRIBUTE::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-getvalue)

[IEnumCERTVIEWATTRIBUTE::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-next)

[IEnumCERTVIEWATTRIBUTE::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewattribute-skip)