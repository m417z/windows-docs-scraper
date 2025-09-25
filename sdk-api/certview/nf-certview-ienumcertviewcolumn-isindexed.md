# IEnumCERTVIEWCOLUMN::IsIndexed

## Description

The **IsIndexed** method reports whether the data in the column is indexed.

## Parameters

### `pIndexed` [out]

A pointer to a variable of type **LONG** that indicates **TRUE** if the data is indexed and **FALSE** if the data is not indexed. This method fails if *pIndexed* is set to **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK and the *pIndexed* is set to **TRUE** or **FALSE**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

One if the column is indexed; otherwise, zero.

## Remarks

This method is used to determine whether the data of the current column referenced by the column-enumeration sequence is indexed.

If the column-enumeration sequence is not referencing a valid column, **IsIndexed** will fail. Use one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next): Moves to the next column in the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip): Skips a specified number of columns.

#### Examples

```cpp
HRESULT  hr;
LONG     bIsindexed;

// pEnumCol is previously instantiated IEnumCERTVIEWCOLUMN object
hr = pEnumCol->IsIndexed(&bIsindexed);
if (S_OK == hr)
    printf( bIsindexed ? "Indexed\n" : "Not indexed\n");
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next)

[IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset)

[IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip)