# IX509Extension::Initialize

## Description

The **Initialize** method initializes an [IX509Extension](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extension) object by using an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and a byte array that contains the [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded extension. The DER-encoded byte array is represented by a Unicode-encoded string. This method is web enabled.

## Parameters

### `pObjectId` [in]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that contains the extension OID.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string.

### `strEncodedData` [in]

A **BSTR** variable that contains the DER-encoded extension value.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The OID could not be found. |

## Remarks

A certificate extension consists of an OID, a Boolean value that identifies whether the extension is critical, and a byte array that contains the extension value. The extension is defined by an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) standard and is encoded by using DER. You must specify the DER-encoded byte array as a string that is either a pure binary sequence or is Unicode encoded. You can specify the type of encoding to apply to the string by using the [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration.

## See also

[IX509Extension](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extension)