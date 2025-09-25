# ITfDisplayAttributeInfo::GetAttributeInfo

## Description

Obtains the display attribute data.

## Parameters

### `pda` [out]

Pointer to a [TF_DISPLAYATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_displayattribute) structure that receives display attribute data.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pda* is invalid. |

## See also

[ITfDisplayAttributeInfo interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfdisplayattributeinfo), [ITfDisplayAttributeMgr::OnUpdateInfo](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfdisplayattributemgr-onupdateinfo), [TF_DISPLAYATTRIBUTE structure](https://learn.microsoft.com/windows/win32/api/msctf/ns-msctf-tf_displayattribute), [ITfDisplayAttributeInfo::SetAttributeInfo](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfdisplayattributeinfo-setattributeinfo)