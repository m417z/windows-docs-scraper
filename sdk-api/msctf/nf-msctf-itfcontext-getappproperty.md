# ITfContext::GetAppProperty

## Description

Obtains an application property.

## Parameters

### `guidProp` [in]

Specifies the property identifier. This can be a custom identifier or one of the [predefined property identifiers](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties).

### `ppProp` [out]

Pointer to an [ITfReadOnlyProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreadonlyproperty) interface pointer that receives the property object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The context owner does not support the property. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_NOTIMPL** | The context owner does not implement this method. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Applications can define unique properties identified by a GUID. Properties are stored as VARIANT data, so the caller must recognize the format and meaning of unique properties to be able to use them.

Application properties differ from text properties, obtained by [ITfContext::GetProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-getproperty), in that, application properties are maintained by the context owner and cannot be modified by a text service. Application properties can only be modified by the context owner.

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [ITfContext::GetProperty](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontext-getproperty), [ITfReadOnlyProperty interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfreadonlyproperty), [Predefined Properties](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties)