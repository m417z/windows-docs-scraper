# ITfContext::GetProperty

## Description

Obtains a text property.

## Parameters

### `guidProp` [in]

Specifies the property identifier. This can be a custom identifier or one of the [predefined property identifiers](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties).

### `ppProp` [out]

Pointer to an [ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty) interface pointer that receives the property object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

An application or text service can define unique properties identified by a GUID. Properties are stored as VARIANT data, so the caller must recognize the format and meaning of unique properties to be able to use them.

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [ITfProperty interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfproperty), [Predefined Properties](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties)