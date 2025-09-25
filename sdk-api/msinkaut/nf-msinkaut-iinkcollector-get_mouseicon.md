# IInkCollector::get_MouseIcon

## Description

Gets or sets the custom mouse icon.

This property is read/write.

## Parameters

## Remarks

The [propputref] function can accept a **NULL** reference, in which case S_OK is returned.

This property provides a custom icon that is used when the [MousePointer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_mousepointer) property is set to [IMP_Custom](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkmousepointer).

You can use the **MouseIcon** property to load either cursor or icon files. The **MouseIcon** property provides your application with access to custom cursors of any size with any desired hot spot location.

## See also

[IInkCollector](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkcollector)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[MousePointer Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_mousepointer)