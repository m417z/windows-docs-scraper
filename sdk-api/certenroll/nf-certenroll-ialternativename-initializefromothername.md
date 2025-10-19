# IAlternativeName::InitializeFromOtherName

## Description

The **InitializeFromOtherName** method initializes the object from an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and the associated raw data (byte array). This method is provided to support the **otherName** field in the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) **AlternativeNames** extension declaration.

``` syntax

----------------------------------------------------------------------
-- AlternativeNames
-- XCN_OID_SUBJECT_ALT_NAME2 (2.5.29.17)
----------------------------------------------------------------------

AltNames ::= SEQUENCE --#public-- OF GeneralName
GeneralNames ::= AltNames

GeneralName ::= CHOICE
{
   otherName               [0] IMPLICIT OtherName,
   rfc822Name              [1] IMPLICIT IA5STRING,
   dNSName                 [2] IMPLICIT IA5STRING,
   x400Address             [3] IMPLICIT SeqOfAny,       -- Not supported
   directoryName           [4] EXPLICIT ANY,
   ediPartyName            [5] IMPLICIT SeqOfAny,
   uniformResourceLocator  [6] IMPLICIT IA5STRING,
   iPAddress               [7] IMPLICIT OCTETSTRING,
   registeredID            [8] IMPLICIT EncodedObjectID -- Not supported
}

OtherName ::= SEQUENCE
{
   type                    EncodedObjectID,
   value                   [0] EXPLICIT NOCOPYANY
}

```

## Parameters

### `pObjectId` [in]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents an OID.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that identifies the type of Unicode encoding applied to the *strRawData* parameter.

### `strRawData` [in]

A **BSTR** variable that contains the name associated with the OID.

### `ToBeWrapped` [in]

A **VARIANT_BOOL** variable that identifies whether the input string contained in the *strRawData* parameter is encoded and saved as an octet string (byte array).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

You can use this function to initialize an [IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename) object from an OID and an associated string value. The string is Unicode encoded. If you specify true for the *ToBeWrapped* parameter, the string is encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER). You can retrieve the OID by calling the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-get_objectid) property. You can retrieve the encoded string or, if *ToBeWrapped* is true, the DER-encoded byte array by calling the [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-get_rawdata) property to retrieve the encoded byte array.

## See also

[IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename)