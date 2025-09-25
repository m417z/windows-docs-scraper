# ITfFnPropertyUIStatus::GetStatus

## Description

Obtains the status of a text service property UI.

## Parameters

### `refguidProp` [in]

Specifies the property identifier. This can be a custom identifier or one of the [predefined property](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties) identifiers.

### `pdw` [out]

Pointer to a **DWORD** that receives the property UI status. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **TF_PROPUI_STATUS_SAVETOFILE** | The property can be serialized. If this value is not present, the property cannot be serialized. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pdw* is invalid. |
| **E_NOTIMPL** | The text service does not support this method. |

## See also

[ITfFnPropertyUIStatus](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnpropertyuistatus)

[Predefined Properties](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties)