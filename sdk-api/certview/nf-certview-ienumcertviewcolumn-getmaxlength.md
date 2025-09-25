# IEnumCERTVIEWCOLUMN::GetMaxLength

## Description

The **GetMaxLength** method retrieves the maximum allowable length, in bytes, for the column data.

 If the column data's type is **PROPTYPE_STRING**, divide the number of bytes by `sizeof(WCHAR)` to determine the maximum number of [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) characters.

## Parameters

### `pMaxLength` [out]

A pointer to a value of **LONG** type that contains the maximum allowable length for the column data. This function will fail if *pMaxLength* is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK and the *pMaxLength* is set to the maximum allowable length for the column data.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the maximum allowable length, in bytes, for the column data.

## Remarks

This method is used to determine the maximum allowable data length for the column currently being referenced by the
column-enumeration sequence.

If the column-enumeration sequence is not referencing a valid column, **GetMaxLength** will fail. Use one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next): Moves to the next column in the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip): Skips a specified number of columns.

To determine whether the column data is indexed, call the [IEnumCERTVIEWCOLUMN::IsIndexed](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-isindexed) method.

#### Examples

```cpp
// pEnumCol is previously instantiated IEnumCERTVIEWCOLUMN object
HRESULT  hr;
LONG     nLength;

// determine database length
hr = pEnumCol->GetMaxLength(&nLength);
if (S_OK == hr)
    printf("max length is %d\n", nLength);
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWCOLUMN::IsIndexed](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-isindexed)

[IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next)

[IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset)

[IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip)