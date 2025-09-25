# IEnroll4::stringToBinaryBlob

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **stringToBinaryBlob** method converts an encoded string to a binary data [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

The **stringToBinaryBlob** method calls the
[CryptStringToBinary](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptstringtobinarya) function. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `Flags` [in]

Value passed to the *dwFlags* parameter of the [CryptStringToBinary](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptstringtobinarya) function. For valid values, see
[CryptStringToBinary](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptstringtobinarya) .

### `pwszString` [in]

Encoded string to be converted to a binary data BLOB.

### `pblobBinary` [out]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that receives the binary data.

### `pdwSkip` [out]

A pointer to **LONG** that receives the number of characters in any skipped strings up to the beginning of actual base64 or hexadecimal strings.

### `pdwFlags` [out]

A pointer to **LONG** that receives the actual format used in the conversion

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)