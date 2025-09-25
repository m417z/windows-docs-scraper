# ITfDisplayAttributeInfo::SetAttributeInfo

## Description

Sets the new attribute data.

## Parameters

### `pda` [in]

Pointer to a [TF_DISPLAYATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_displayattribute) structure that contains the new display attribute data.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The display attribute provider does not support attribute modification. |
| **E_INVALIDARG** | *pda* is invalid. |

## Remarks

The implementation of this method should not call [ITfDisplayAttributeMgr::OnUpdateInfo](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdisplayattributemgr-onupdateinfo) in response to this method. The caller must do so. This avoids redundant notifications if more than one attribute is modified. The caller must eventually call **ITfDisplayAttributeMgr::OnUpdateInfo** so that other clients will receive an attribute update notification.

## See also

[ITfDisplayAttributeInfo interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfdisplayattributeinfo), [ITfDisplayAttributeMgr::OnUpdateInfo](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfdisplayattributemgr-onupdateinfo), [TF_DISPLAYATTRIBUTE structure](https://learn.microsoft.com/windows/win32/api/msctf/ns-msctf-tf_displayattribute), [ITfDisplayAttributeInfo::GetAttributeInfo](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfdisplayattributeinfo-getattributeinfo)