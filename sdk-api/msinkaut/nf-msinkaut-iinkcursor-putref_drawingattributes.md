# IInkCursor::putref_DrawingAttributes

## Description

Gets or sets the drawing attributes to apply to ink as it is drawn.

This property is read/write.

## Parameters

## Remarks

The drawing attributes specify the appearance of the stroke. For example, you can specify the style and color of a pen.

A cursor can have different drawing attributes for each [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) with which it comes in contact. If you do not specify drawing attributes for a cursor, it uses the default drawing attributes of the **InkCollector** object. These default attributes are set with the [DefaultDrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_defaultdrawingattributes) property of the **InkCollector** object.

Successive calls to the **DrawingAttributes** property change only the drawing attributes of new strokes. They do not apply to strokes that are already collected or being collected.

**Note** This property behaves differently than the [DefaultDrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_defaultdrawingattributes) property. Although the **DefaultDrawingAttributes** property specifies the drawing attributes that are applied to a new cursor, the **DrawingAttributes** property specifies the drawing attributes for ink that is yet to be collected.

## See also

[DefaultDrawingAttributes Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_defaultdrawingattributes)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[InkCursor Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursor)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)