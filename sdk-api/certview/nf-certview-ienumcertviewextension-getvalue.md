# IEnumCERTVIEWEXTENSION::GetValue

## Description

The **GetValue** method retrieves the value of the current extension in the extension-enumeration sequence.

## Parameters

### `Type` [in]

Data type for the returned data. This parameter can be used to specify that the extension data be decoded before being returned. If PROPTYPE_BINARY is specified, the data is not decoded but instead returned in its raw format.

 Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_BINARY** | The extension value is retrieved as is and is ASN.1 encoded if necessary. |
| **PROPTYPE_DATE** | Extension value is returned as a date/time. |
| **PROPTYPE_LONG** | Extension value is returned as a signed long. |
| **PROPTYPE_STRING** | The extension value is ASN.1 encoded as an IA5 string. |

### `Flags` [in]

Flag that denotes the output format for the returned data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CV_OUT_BASE64** | BASE64 without BEGIN/END |
| **CV_OUT_BASE64HEADER** | BASE64 with BEGIN CERTIFICATE and END CERTIFICATE |
| **CV_OUT_BASE64REQUESTHEADER** | BASE64 with BEGIN NEW CERTIFICATE REQUEST and END NEW CERTIFICATE REQUEST |
| **CV_OUT_BINARY** | Binary |
| **CV_OUT_HEX** | Hexadecimal string |
| **CV_OUT_HEXADDR** | Hexadecimal string with address/offset |
| **CV_OUT_HEXASCII** | Hexadecimal string with ASCII |
| **CV_OUT_HEXASCIIADDR** | Hexadecimal string with ASCII and address/offset |

### `pvarValue` [out]

A pointer to a value of **VARIANT** type that contains the data for the currently referenced extension. This method fails if the *pvarValue* parameter is **NULL**. Upon successful completion of this function, *pvarValue* contains the extension data currently referenced by the extension-enumeration sequence. The caller is responsible for calling [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) when done with the data in *pvarValue*.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **Variant** that represents the data in the extension.

## Remarks

This method is used to retrieve the data in the extension currently being referenced by the
extension-enumeration sequence.

If the extension-enumeration sequence is not referencing a valid extension, **GetValue** fails. Use one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWEXTENSION::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-reset): Moves to the next extension in the enumeration sequence.
* [IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next): Moves to the next extension in the enumeration sequence.
* [IEnumCERTVIEWEXTENSION::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-skip): Skips a specified number of extensions.

This method fails if the extension-enumeration sequence was obtained by a call to the
[ICertView::EnumCertViewColumn](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-enumcertviewcolumn) method because enumeration sequences obtained by that method contain only schema information.

#### Examples

```cpp
VARIANT     var;
LONG        Index;
HRESULT     hr;
SYSTEMTIME  systime;

VariantInit(&var);

// Enumerate each extension
// pEnumExt is previously instantiated IEnumCERTVIEWEXTENSION object
while (S_OK == pEnumExt->Next(&Index))
{
    hr = pEnumExt->GetValue(PROPTYPE_BINARY, CV_OUT_HEX, &var);
    if (FAILED(hr))
    {
        printf("Failed GetValue - %x\n", hr);
        break;
    }
    switch(var.vt)
    {
        case VT_EMPTY:
            printf("VT_EMPTY\n");
            break;
        case VT_BSTR:
            printf("BSTR:%ws\n", var.bstrVal);
            break;
        case VT_DATE:
            VariantTimeToSystemTime(var.date, &systime);
            printf("%d.%d.%d %02d:%02d:%02d\n",
                   systime.wMonth,
                   systime.wDay,
                   systime.wYear,
                   systime.wHour,
                   systime.wMinute,
                   systime.wSecond );
            break;
        case VT_I2:
            printf("%d\n", var.iVal);
            break;
        case VT_I4:
            printf("%d\n", var.lVal);
            break;
        default:
            printf("type is:%i\n", var.vt);
            break;
    }
}
// Free resources.
VariantClear( &var );
```

## See also

[ICertView::EnumCertViewColumn](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-enumcertviewcolumn)

**IEnumCERTVIEWEXTENSION**

[IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next)

[IEnumCERTVIEWEXTENSION::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-reset)

[IEnumCERTVIEWEXTENSION::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-skip)