# IEnumCERTVIEWROW::EnumCertViewColumn

## Description

The **EnumCertViewColumn** method obtains an instance of a column-enumeration sequence for the current row of the row-enumeration sequence.

## Parameters

### `ppenum` [out]

A pointer to a pointer of [IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn) type.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a column-enumeration sequence object.

## Remarks

The
column-enumeration sequence obtained by this call can be used to enumerate the columns associated with the certificate in the current row. This enumeration can be accessed through the methods of the [IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn) interface.

To reference a different row, call one of the following methods to navigate through the row-enumeration sequence:

* [IEnumCERTVIEWROW::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next): Moves to the next row in the enumeration sequence.
* [IEnumCERTVIEWROW::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-skip): Skips a specified number of rows.

#### Examples

```cpp
// pEnumRow is previously instantiated pointer to IEnumCERTVIEWROW
HRESULT               hr;
LONG                  Index;
IEnumCERTVIEWCOLUMN * pEnumCol = NULL;
// obtain enumerator for columns
hr = pEnumRow->EnumCertViewColumn(&pEnumCol);
if ( FAILED( hr ))
{
    printf("Failed EnumCertViewColumn - %x\n", hr );
    goto error;
}
// enumerate each column
while (S_OK == pEnumCol->Next(&Index))
{
    // Use this column as needed.
}
error:

// Free resources.
if ( NULL != pEnumCol )
    pEnumCol->Release();
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWROW](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewrow)

[IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next)

[IEnumCERTVIEWROW::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-reset)

[IEnumCERTVIEWROW::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-skip)