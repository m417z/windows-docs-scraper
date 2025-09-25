# IEnumCERTVIEWROW::EnumCertViewAttribute

## Description

The **EnumCertViewAttribute** method obtains an instance of an attribute-enumeration sequence for the current row of the row-enumeration sequence.

## Parameters

### `Flags` [in]

|  |  |
| --- | --- |
| **C++** | A **LONG** value. Must be zero. |
| **VB** | A **Long** value. Must be zero. |

### `ppenum` [out]

A pointer to a pointer of [IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute) type. Upon successful completion of this method, *ppenum* is set to a pointer of **IEnumCERTVIEWATTRIBUTE** type.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The returned value is an attribute-enumeration sequence object.

## Remarks

The
attribute-enumeration sequence obtained by this call can be used to enumerate the attributes associated with the certificate in the current row. This enumeration can be accessed through the methods of the [IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute) interface.

To reference a different row, call one of the following methods to navigate through the row-enumeration sequence:

* [IEnumCERTVIEWROW::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next): Moves to the next row in the enumeration sequence.
* [IEnumCERTVIEWROW::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-skip): Skips a specified number of rows.

#### Examples

```cpp
// pEnumRow is previously instantiated pointer to IEnumCERTVIEWROW
HRESULT                  hr;
LONG                     Index;
IEnumCERTVIEWATTRIBUTE * pEnumAttr = NULL;

// obtain enumerator for attributes
hr = pEnumRow->EnumCertViewAttribute(0, &pEnumAttr);
if (FAILED(hr))
{
    printf("Failed EnumCertViewAttribute - %x\n", hr);
    goto error;
}
// enumerate each attribute
while (S_OK == pEnumAttr->Next(&Index))
{
    // Use this attribute as needed.
}
error:

// Free resources.
if (NULL != pEnumAttr)
    pEnumAttr->Release();
```

## See also

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)

[IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow)

[IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next)

[IEnumCERTVIEWROW::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-reset)

[IEnumCERTVIEWROW::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-skip)