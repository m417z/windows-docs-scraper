# ITfDisplayAttributeInfo::Reset

## Description

Resets the display attribute data to its default value.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The display attribute provider does not support attribute modification. |

## Remarks

The implementation of this method should not call [ITfDisplayAttributeMgr::OnUpdateInfo](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdisplayattributemgr-onupdateinfo) in response to this method. The caller must do so. This avoids redundant notifications if more than one attribute is modified. The caller must eventually call **ITfDisplayAttributeMgr::OnUpdateInfo** so that other clients will receive an attribute update notification.

## See also

[ITfDisplayAttributeInfo interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfdisplayattributeinfo), [ITfDisplayAttributeMgr::OnUpdateInfo](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfdisplayattributemgr-onupdateinfo),