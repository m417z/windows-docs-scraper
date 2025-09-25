# IEnumCERTVIEWCOLUMN::GetName

## Description

The **GetName** method retrieves the nonlocalized name of the current column in the column-enumeration sequence.

## Parameters

### `pstrOut` [out]

A pointer to a variable of **BSTR** type that contains the name of the column.

## Return value

### C++

If the method succeeds, the method returns S_OK and the *pstrOut* parameter contains the name of the column.

To use this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and pass the address of this variable as *pstrOut*. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **String** that contains the name of the column.

## Remarks

This method is used to retrieve the nonlocalized name of the column currently referenced by the
column-enumeration sequence.

If the column-enumeration sequence is not referencing a valid column, **GetName** will fail. Use one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next): Moves to the next column in the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip): Skips a specified number of columns.

#### Examples

```cpp
BSTR       bstrColName = NULL;
HRESULT    hr;

// pEnumCol is previously instantiated IEnumCERTVIEWCOLUMN object
hr = pEnumCol->GetName(&bstrColName);
if (S_OK == hr)
    printf("Column name is %ws\n", bstrColName);

// done processing, clear resources
if (NULL != bstrColName)
    SysFreeString(bstrColName);
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next)

[IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset)

[IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip)