# ITfFnPropertyUIStatus::SetStatus

## Description

Modifies the status of a text service property UI.

## Parameters

### `refguidProp` [in]

Specifies the property identifier. This can be a custom identifier or one of the [predefined property](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties) identifiers.

### `dw` [in]

Contains the new property UI status. See the *pdw* parameter of [ITfFnPropertyUIStatus::GetStatus](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnpropertyuistatus-getstatus) for possible values.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The text service does not support this method. |

## See also

[ITfFnPropertyUIStatus](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnpropertyuistatus)

[ITfFnPropertyUIStatus::GetStatus](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnpropertyuistatus-getstatus)

[Predefined Properties](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties)