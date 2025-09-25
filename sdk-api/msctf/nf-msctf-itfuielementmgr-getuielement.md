# ITfUIElementMgr::GetUIElement

## Description

The **ITfUIElementMgr::GetUIElement** method gets the [ITfUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfuielement) interface of the element id.

## Parameters

### `dwUIELementId` [in]

[in] The element id to get the [ITfUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfuielement) interface.

### `ppElement` [out]

[out] A pointer to receive [ITfUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfuielement) interface.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |