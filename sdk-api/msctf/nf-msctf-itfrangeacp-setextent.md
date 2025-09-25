# ITfRangeACP::SetExtent

## Description

Sets the application character position and length of the range object.

## Parameters

### `acpAnchor` [in]

Contains the application character position of the range start anchor.

### `cch` [in]

Contains the number of characters in the range.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method should only be called by the owner of the ACP-based context because the character position and range length will only have meaning to a caller that recognizes the text store implementation.

## See also

[ITfRangeACP](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrangeacp)

[ITfRangeACP::GetExtent](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrangeacp-getextent)