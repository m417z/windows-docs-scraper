# ITfDisplayAttributeMgr::EnumDisplayAttributeInfo

## Description

Obtains a display attribute enumerator object.

## Parameters

### `ppEnum` [out]

Pointer to an [IEnumTfDisplayAttributeInfo](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfdisplayattributeinfo) interface pointer that receives the enumerator object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | The enumerator object cannot be initialized. |

## See also

[ITfDisplayAttributeMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfdisplayattributemgr), [IEnumTfDisplayAttributeInfo interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumtfdisplayattributeinfo)