# ITfUIElementSink::BeginUIElement

## Description

The **ITfUIElementSink::BeginUIElement** method is called when the UIElement started. This sink can let the textservice to draw or not to draw the UI element.

## Parameters

### `dwUIElementId` [in]

[in] Id of the UIElement that was started.

### `pbShow`

[in, out] Return **true** if the application does not draw the UIElement content and the text service draws its original UI content. Return **false** if the application draws the UIElement's content and stops the text service from drawing it. The application can get the [ITfUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfuielement) interface by using [ITfUIElementMgr::GetUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfuielementmgr-getuielement) and it can evaluate if it can handle the UIElement by QI with **IID_ITfCandidateListUIElement** or with other UIElement interfaces. The application can always return **FALSE** if it is unknown or it cannot be handled. In this case, the text service will not show any extra UI on the screen. This is a good way for some full screen applications. Alternatively, the application can return **TRUE** to use TextService's UI on some particular or unknown UIs.

## Return value

The TSF manager ignores the return value of this method.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |