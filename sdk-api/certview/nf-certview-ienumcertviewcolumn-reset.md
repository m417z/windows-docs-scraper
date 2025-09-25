# IEnumCERTVIEWCOLUMN::Reset

## Description

The **Reset** method moves to the beginning of the column-enumeration sequence.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Upon successful completion of this method, call the
[IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next) method to reference the first column in the enumeration. After this second call is made, the information in the column can be obtained by calling one of the following methods:

* [IEnumCERTVIEWCOLUMN::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getname): Retrieves the nonlocalized name of the column.
* [IEnumCERTVIEWCOLUMN::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getdisplayname): Retrieves the localized name of the column.
* [IEnumCERTVIEWCOLUMN::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getvalue): Retrieves the data in the column.
* [IEnumCERTVIEWCOLUMN::GetType](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-gettype): Retrieves the type of data in the column.
* [IEnumCERTVIEWCOLUMN::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getmaxlength): Retrieves the maximum length, in bytes, of the column.

#### Examples

```cpp
// pEnumCol is previously instantiated IEnumCERTVIEWCOLUMN object
HRESULT    hr;
LONG        Index;
hr = pEnumCol->Reset();
if (S_OK != hr)
    printf("Unable to reset pEnumCol\n");
    // call appropriate error handler / exit routine
else
{
    // now at the beginning of the columns
    // enumerate each column
    while (S_OK == pEnumCol->Next(&Index))
    {
        // Use each column as needed.
    }
}
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWCOLUMN::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getdisplayname)

[IEnumCERTVIEWCOLUMN::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getmaxlength)

[IEnumCERTVIEWCOLUMN::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getname)

[IEnumCERTVIEWCOLUMN::GetType](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-gettype)

[IEnumCERTVIEWCOLUMN::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-getvalue)