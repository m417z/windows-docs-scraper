# IEnumCERTVIEWCOLUMN::GetValue

## Description

The **GetValue** method retrieves the data value contained in the current column in the column-enumeration sequence.

## Parameters

### `Flags` [in]

An identifier that denotes the output format for the retrieved data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CV_OUT_BASE64** | BASE64 without BEGIN/END |
| **CV_OUT_BASE64HEADER** | BASE64 with BEGIN CERTIFICATE and END CERTIFICATE |
| **CV_OUT_BASE64REQUESTHEADER** | BASE64 with BEGIN NEW CERTIFICATE REQUEST and END NEW CERTIFICATE REQUEST |
| **CV_OUT_BASE64X509CRLHEADER** | BASE64 with BEGIN X509 CRL and END X509 CRL |
| **CV_OUT_BINARY** | Binary |
| **CV_OUT_HEX** | Hexadecimal string |
| **CV_OUT_HEXADDR** | Hexadecimal string with address/offset |
| **CV_OUT_HEXASCII** | Hexadecimal string with ASCII |
| **CV_OUT_HEXASCIIADDR** | Hexadecimal string with ASCII and address/offset |

### `pvarValue` [out]

A pointer to value of **VARIANT** type that contains the data column. This method fails if *pvarValue* is **NULL**. Upon successful completion of this method, *pvarValue* contains the data in the column. The caller is responsible for calling [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) when done with this data.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **Variant** that represents the data in the column.

## Remarks

This method is used to retrieve the data in the column currently being referenced by the
column-enumeration sequence.

If the column-enumeration sequence is not referencing a valid column, **GetValue** will fail. Use one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset): Moves to the beginning of the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next): Moves to the next column in the enumeration sequence.
* [IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip): Skips a specified number of columns.

#### Examples

```cpp
HRESULT     hr;
VARIANT     var;
SYSTEMTIME  systime;

VariantInit(&var);

// pEnumCol is previously instantiated IEnumCERTVIEWCOLUMN object
hr = pEnumCol->GetValue(CV_OUT_HEX, &var);
if ( FAILED (hr) )
{
    printf("Failed GetValue - %x\n", hr);
    goto error;
}
switch( var.vt )
{
    case VT_EMPTY:
        printf( "VT_EMPTY\n" );
        break;
    case VT_BSTR:
        printf("%ws\n", var.bstrVal );
        break;
    case VT_DATE:
        VariantTimeToSystemTime( var.date, &systime );
        printf("%d.%d.%d %02d:%02d:%02d\n",
               systime.wMonth,
               systime.wDay,
               systime.wYear,
               systime.wHour,
               systime.wMinute,
               systime.wSecond );
        break;
    case VT_I2:
        printf("%d\n", var.iVal );
        break;
    case VT_I4:
        printf("%d\n", var.lVal );
        break;
    default:
        printf("type is:%i\n", var.vt );
        break;
}
// done processing, clear resources
VariantClear( &var );
```

## See also

[IEnumCERTVIEWCOLUMN](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewcolumn)

[IEnumCERTVIEWCOLUMN::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-next)

[IEnumCERTVIEWCOLUMN::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-reset)

[IEnumCERTVIEWCOLUMN::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewcolumn-skip)