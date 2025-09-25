# IEnumCERTVIEWROW::EnumCertViewExtension

## Description

The **EnumCertViewExtension** method obtains an instance of an extension-enumeration sequence for the current row of the row-enumeration sequence.

## Parameters

### `Flags` [in]

|  |  |
| --- | --- |
| **C++** | A **LONG** value. Must be zero. |
| **VB** | A **Long** value. Must be zero. |

### `ppenum` [out, retval]

A pointer to a pointer of [IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension) type.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is an extension-enumeration sequence object.

## Remarks

The
extension-enumeration sequence obtained by this call can be used to enumerate the extensions associated with the certificate in the current row. This enumeration can be accessed through the methods of the [IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension) interface.

To reference a different row, call one of the following methods to navigate through the row-enumeration sequence:

* [IEnumCERTVIEWROW::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next): Moves to the next row in the enumeration sequence.
* [IEnumCERTVIEWROW::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-skip): Skips a specified number of rows.

#### Examples

```cpp
// pEnumRow is previously instantiated pointer to IEnumCERTVIEWROW.
LONG       Index;
HRESULT    hr;
IEnumCERTVIEWEXTENSION * pEnumExt = NULL;
// Obtain enumerator for extensions.
hr = pEnumRow->EnumCertViewExtension(0, &pEnumExt);
if (FAILED(hr))
{
    printf("Failed EnumCertViewExtension - %x\n", hr);
    goto error;
}
// Enumerate each extension.
while (S_OK == pEnumExt->Next(&Index))
{
    // Use this extension as needed.
}
error:

// Free resources.
if (NULL != pEnumExt)
    pEnumExt->Release();
```

## See also

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

[IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow)

[IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next)

[IEnumCERTVIEWROW::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-reset)

[IEnumCERTVIEWROW::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-skip)