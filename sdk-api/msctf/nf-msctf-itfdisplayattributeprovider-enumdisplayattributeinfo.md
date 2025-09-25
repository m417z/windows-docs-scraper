# ITfDisplayAttributeProvider::EnumDisplayAttributeInfo

## Description

Obtains an enumerator that contains all display attribute info objects supported by the display attribute provider.

## Parameters

### `ppEnum` [out]

Pointer to an [IEnumTfDisplayAttributeInfo](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfdisplayattributeinfo) interface pointer that receives the enumerator object. The caller must release this interface when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[IEnumTfDisplayAttributeInfo](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfdisplayattributeinfo)

[ITfDisplayAttributeProvider](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdisplayattributeprovider)