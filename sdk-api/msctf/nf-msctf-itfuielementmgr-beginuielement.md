# ITfUIElementMgr::BeginUIElement

## Description

The **ITfUIElementMgr::BeginUIElement** method is called by a text service before showing UI. The value returned determines whether the UI for the text service should be shown or not.

## Parameters

### `pElement` [in]

[in] A pointer to the [ITfUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfuielement) interface of the UIElement object.

### `pbShow`

[in, out] If false is returned, the application may draw the UI by itself and a text service does not show its own UI for this UI element.

### `pdwUIElementId` [out]

[out] A pointer to receive the ID of this UI element.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_UNEXPECTED** | Recursion call of [ITfUIElementMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfuielementmgr) interface happened. |