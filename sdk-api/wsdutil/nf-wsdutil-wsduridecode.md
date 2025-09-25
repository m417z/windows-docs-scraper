# WSDUriDecode function

## Description

Decodes a URI according to the rules in RFC2396.

## Parameters

### `source` [in]

Contains the URI to be decoded.

### `cchSource` [in]

Specifies the length of *source* in characters.

### `destOut` [out]

Pointer to a string that contains the decoded URI. If *destOut* is not **NULL**, the calling application should free the allocated string by calling [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory).

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

**WSDUriDecode** decodes any encoded characters in *source*. These characters are identified by a percent sign (%) followed by two hexadecimal digits. **WSDUriDecode** decodes single-byte components of multi-byte characters and converts them back to wide character representation in *destOut*.