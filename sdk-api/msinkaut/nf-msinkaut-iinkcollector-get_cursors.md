# IInkCollector::get_Cursors

## Description

Gets the collection of cursors that are available for use in the inking region. Each cursor corresponds to the tip of a pen or other ink input device.

This property is read-only.

## Parameters

## Remarks

Cursors are local to an [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object.

Any new cursors that the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) encounters are added to the returned collection of cursors, although the returned cursors are not necessarily returned in the order in which the **InkCollector** encounters them.

When a mouse is enabled as an input device on the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) (when the *useMouse* parameter of the [SetAllTabletsMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setalltabletsmode) method is **TRUE**), the mouse is added to the [IInkCursors](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursors) collection after the **InkCollector** encounters any other cursor, such as a pen. This is because the pen also acts like a mouse.

**Note** The [CursorInRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursorinrange) event is received for the mouse cursor after any other cursor, such as a pen, draws a stroke (which fires the [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke) event).

The [IInkCursors](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursors) collection is reset (count set to 0, containing no objects) when:

* The tablet mode is changed (for example, from [SetSingleTabletIntegratedMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setsingletabletintegratedmode) to [SetAllTabletsMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setalltabletsmode)).
* The [SetSingleTabletIntegratedMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setsingletabletintegratedmode) method is called.

## See also

[IInkCollector](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkcollector)

[IInkCursors Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursors)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[MouseIcon Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_mouseicon)

[MousePointer Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_mousepointer)

[SetAllTabletsMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setalltabletsmode)

[SetSingleTabletIntegratedMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setsingletabletintegratedmode)