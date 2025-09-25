# ITfUIElement::IsShown

## Description

The **ITfUIElement::IsShown** method returns true if the UI is currently shown by a text service; otherwise false.

## Parameters

### `pbShow` [out]

[out] A pointer to bool of the current show status of the original UI of this element.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |