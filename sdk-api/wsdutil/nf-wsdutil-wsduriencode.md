# WSDUriEncode function

## Description

Encodes a URI according to URI encoding rules in RFC2396.

## Parameters

### `source` [in]

Contains the URI to be encoded.

### `cchSource` [in]

Specifies the length of *source* in characters.

### `destOut` [out]

Pointer to a string that contains the encoded URI. If *destOut* is not **NULL**, the calling application should free the allocated string by calling [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory).

### `cchDestOut` [out, optional]

Specifies the length of *destOut* in characters.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Function completed successfully. |
| **E_INVALIDARG** | *source* is **NULL** or *cchSource* is 0. |
| **E_FAIL** | The length in characters of *source* exceeds **WSD_MAX_TEXT_LENGTH** (8192). |
| **E_POINTER** | *destOut* is **NULL**. |

## Remarks

**WSDUriEncode** encodes certain characters in *source* into an escaped encoding format of %XY, where X and Y are hexadecimal digits corresponding to the single-byte representation of that character. Wide characters that occupy multiple bytes are first rendered into UTF-8 multi-byte format, and then escaped into encoded characters.

**WSDUriEncode** does not encode single-byte alphanumeric characters. It does encode percent signs (%) in *source*.