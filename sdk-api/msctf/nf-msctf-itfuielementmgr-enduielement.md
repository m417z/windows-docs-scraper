# ITfUIElementMgr::EndUIElement

## Description

The **ITfUIElementMgr::EndUIElement** method is called by a text service when the element of UI is hidden.

## Parameters

### `dwUIElementId` [in]

[in] The element id to hide the UI element.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_UNEXPECTED** | Recursion call of [ITfUIElementMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfuielementmgr) interface happened. |