# IEnumCERTVIEWCOLUMN::Skip

## Description

The **Skip** method skips a specified number of columns in the column-enumeration sequence.

## Parameters

### `celt` [in]

The number of columns to skip. A positive value for the *celt* parameter causes the column-enumeration sequence to skip forward in the enumeration sequence. A negative value causes column-enumeration to skip backward in the enumeration sequence.

## Return value

### VB

If the method succeeds, the method returns S_OK.

A return value of E_INVALIDARG indicates that a negative value in the *celt* parameter caused the column-enumeration sequence index to become less than zero.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Upon successful completion of this function, call the
[IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next) method to reference the current column in the column-enumeration sequence. After this second call is made, the information in the column can be obtained by calling one of the following methods:

* [IEnumCERTVIEWCOLUMN::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getname): Retrieves the nonlocalized name of the column.
* [IEnumCERTVIEWCOLUMN::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getdisplayname): Retrieves the localized name of the column.
* [IEnumCERTVIEWCOLUMN::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getvalue): Retrieves the data in the column.
* [IEnumCERTVIEWCOLUMN::GetType](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-gettype): Retrieves the type of data in the column.
* [IEnumCERTVIEWCOLUMN::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getmaxlength): Retrieves the maximum length, in bytes, of the column.

The column-enumeration sequence maintains an internal zero-based index. The call to the **Skip** method causes this index to increase or decrease based on the setting of the *celt* parameter.

If a negative value of the *celt* parameter causes the index to be less than zero, the behavior of subsequent calls to [Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next) is undefined.

If a positive value of the *celt* parameter causes the index to exceed the last row in the enumeration sequence, a subsequent call to the [Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next) method will fail.

#### Examples

```cpp
HRESULT  hr;
LONG     Index;

// pEnumCol is previously instantiated IEnumCERTVIEWCOLUMN object
// skip the next five columns
hr = pEnumCol->Skip(5);
if (S_OK == hr)
{
    // get the next column
    hr = pEnumCol->Next(&Index);
    if (S_OK == hr)
    {
        // Use this column as needed.
    }
}
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset)

[IEnumCERTVIEWCOLUMN:Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next)