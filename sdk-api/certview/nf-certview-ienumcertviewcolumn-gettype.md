# IEnumCERTVIEWCOLUMN::GetType

## Description

The **GetType** method retrieves the data type of the current column in the column-enumeration sequence.

## Parameters

### `pType` [out]

A pointer to a variable of **LONG** type that denotes the data type of the column referenced by the column-enumeration sequence. For a table of the valid data types, see Remarks. This method fails if the *pType* parameter is set to **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value represents the data type of the column. For a table of the valid data types, see Remarks.

## Remarks

This method is used to determine the data type of the column currently referenced by the
column-enumeration sequence. The valid data types are listed in the following table.

| Data type | Meaning |
| --- | --- |
| PROPTYPE_BINARY | Binary data |
| PROPTYPE_DATE | Date/time |
| PROPTYPE_LONG | Signed long |
| PROPTYPE_STRING | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string |

If the column-enumeration sequence is not referencing a valid column, **GetType** will fail. Use one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next): Moves to the next column in the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip): Skips a specified number of columns.

#### Examples

```cpp
LONG     nType;
HRESULT  hr;

// pEnumCol is a previously instantiated IEnumCERTVIEWCOLUMN object.
hr = pEnumCol->GetType(&nType);
if (S_OK == hr)
{
    switch (nType)
    {
        case PROPTYPE_BINARY:
            printf("Type is Binary\n");
            break;
        case PROPTYPE_DATE:
            printf("Type is Date+Time\n");
            break;
        case PROPTYPE_LONG:
            printf("Type is Signed long\n");
            break;
        case PROPTYPE_STRING:
            printf("Type is Unicode String\n");
            break;
        default:
            printf("Type is unknown\n");
            break;
    }
}
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next)

[IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset)

[IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip)