# IInkCursor::get_Inverted

## Description

Gets a value that indicates whether the cursor is the inverted end of the pen.

This property is read-only.

## Parameters

## Remarks

Inverted cursors are generally associated with erasing. A pen might have one end that is intended for drawing and another intended for erasing. For more information about erasing ink, see [Erasing Ink with the Pen](https://learn.microsoft.com/windows/desktop/tablet/erasing-ink-with-the-pen).

Whether or not you use the **Inverted** property is entirely up to the needs of your application. Applications are not required to inspect inverted cursors, and the *ink collector* applies default drawing attributes to inverted cursors just as it does to cursors that are not inverted.

**Note** Accessing this property within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: **WM_ACTIVATE**, **WM_ACTIVATEAPP**, **WM_NCACTIVATE**, **WM_PAINT**; **WM_SYSCOMMAND** if *wParam* is set to **SC_HOTKEY** or **SC_TASKLIST**; and **WM_SYSKEYDOWN** (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

## See also

[InkCursor Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursor)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)