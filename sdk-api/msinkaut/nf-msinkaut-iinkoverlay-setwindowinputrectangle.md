# IInkOverlay::SetWindowInputRectangle

## Description

Sets the window rectangle, in pixels, within which ink is drawn.

## Parameters

### `WindowInputRectangle` [in]

The rectangle, in window coordinates, on which ink is drawn.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | The rectangle coordinates are invalid (for example, width/height of 0). |
| **E_INK_COLLECTOR_BUSY** | Cannot update mappings while in the middle of a stroke. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_OVERLAPPING_INPUT_RECT** | The window input rectangle overlaps with the window input rectangle of an enabled InkCollector. |

## Remarks

The E_INK_OVERLAPPING_INPUT_RECT error is returned if the window input rectangle of an enabled ink collector (set with the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property) overlaps the window input rectangle of another enabled ink collector.

**Note** Overlap can occur without an error as long as only one of the input rectangles is enabled at any known time.

By default, the window input rectangle is set to {0,0,0,0}. This default rectangle maps to the size of the entire window.

To reset the window input rectangle to its default behavior (an empty rectangle with coordinates {0,0,0,0}), pass {0,0,0,0} in the call to [SetWindowInputRectangle](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setwindowinputrectangle), and not **NULL**.

You cannot pass in a rectangle where the value of the [Right](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_right) property is less than the value of the [Left](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_left) property; or where the value of the [Bottom](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_bottom) property is less than the value of the [Top](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_top) property. For example, a rectangle with parameters of {500, 500, 400, 400} is not valid.

**Caution** If you set the window input rectangle to overlap a splitter control or the borders of the window, unpredictable results may occur when the window is resized.

**Note** Calling this method within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: **WM_ACTIVATE**, **WM_ACTIVATEAPP**, **WM_NCACTIVATE**, **WM_PAINT**; **WM_SYSCOMMAND** if *wParam* is set to **SC_HOTKEY** or **SC_TASKLIST**; and **WM_SYSKEYDOWN** (when processing Alt+TAB or Alt+ESC key combinations). This is an issue with single-threaded apartment model applications.

## See also

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled)

[GetWindowInputRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-getwindowinputrectangle)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)