# IX509Extension::get_RawData

## Description

The **RawData** property retrieves a byte array that contains the extension value. The byte array is represented by a Unicode-encoded string.

This property is read-only.

## Parameters

## Remarks

A certificate extension is defined by an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) structure, and the extension is encoded into a byte array by using DER. The byte array is returned in a string to simplify use in languages other than C++. You can use the [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration to specify the type of Unicode encoding to apply to the string. You can call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-initialize) method to specify the extension.

## See also

[IX509Extension](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extension)