# ITextStoreACPServices::CreateRange

## Description

Creates a range object from two ACP values.

## Parameters

### `acpStart` [in]

Contains the starting position of the range.

### `acpEnd` [in]

Contains the ending position of the range.

### `ppRange` [out]

Pointer to an [ITfRangeACP](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrangeacp) interface pointer that receives the range object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppRange* is invalid. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITextStoreACPServices interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itextstoreacpservices), [ITfRangeACP interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrangeacp)