# IInkOverlay::put_Enabled

## Description

Gets or sets a value that specifies whether the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object collects pen input (in-air packets, cursor in range events, and so on).

This property is read/write.

## Parameters

## Remarks

If an enabled object's window input rectangle (set in the constructor or with the [SetWindowInputRectangle](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setwindowinputrectangle) method) of an enabled object overlaps the window input rectangle of another enabled object, the E_INK_OVERLAPPING_INPUT_RECT error is returned. Overlap can occur without an error as long as only one of the input rectangles is enabled at any known time.

While an object is not enabled, you receive no events.

When a container control has its [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property set to **FALSE**, all of its contained controls are disabled as well.

You cannot set the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property to **FALSE** while the object is collecting ink ([CollectingInk](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectingink) property is **TRUE**).

We recommend that you set [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) set to **FALSE** when the application shuts down.

**Note** Setting this property within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: **WM_ACTIVATE**, **WM_ACTIVATEAPP**, **WM_NCACTIVATE**, **WM_PAINT**; **WM_SYSCOMMAND** if *wParam* is set to SC_HOTKEY or SC_TASKLIST; and **WM_SYSKEYDOWN** (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

This property must be set to **FALSE** before setting or calling specific properties and methods of the object. If you try to change the specified properties or methods, an error occurs. The following properties and methods cannot be set or called unless the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property is first set to **FALSE**:

Properties

* [AttachMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_attachmode)
* [hWnd](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_hwnd)
* [Ink](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_ink)
* [MarginX](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_marginx)
* [MarginY](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_marginy)

Methods

* [SetAllTabletsMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setalltabletsmode)
* [SetSingleTabletIntegratedMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setsingletabletintegratedmode)

## See also

[AttachMode Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_attachmode)

[CollectingInk Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectingink)

[CollectionMode Property [InkCollector Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectionmode)

[EditingMode Property [InkOverlay Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_editingmode)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[Ink](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_ink)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[MarginX Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_marginx)

[MarginY Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_marginy)

[SetAllTabletsMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setalltabletsmode)

[SetSingleTabletIntegratedMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setsingletabletintegratedmode)

[SetWindowInputRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setwindowinputrectangle)

[hWnd Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_hwnd)