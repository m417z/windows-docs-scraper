# ITfDisplayAttributeMgr::GetDisplayAttributeInfo

## Description

Obtains a display attribute data object.

## Parameters

### `guid` [in]

Contains a GUID that identifies the display attribute data requested. This value is obtained by obtaining the GUID_PROP_ATTRIBUTE property for the range of text. For more information, see [ITfContext::GetProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-getproperty) and [ITfContext::TrackProperties](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-trackproperties).

### `ppInfo` [out]

Pointer to an [ITfDisplayAttributeInfo](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdisplayattributeinfo) interface pointer that receives the object.

### `pclsidOwner` [out]

Pointer to a CLSID value that receives the CLSID of the display attribute provider. This parameter can be **NULL** if the CLSID is not required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfDisplayAttributeMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfdisplayattributemgr), [IEnumTfDisplayAttributeInfo interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumtfdisplayattributeinfo), [ITfContext::GetProperty](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontext-getproperty), [ITfContext::TrackProperties](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontext-trackproperties)