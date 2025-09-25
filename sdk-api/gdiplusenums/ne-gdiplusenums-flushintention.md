# FlushIntention enumeration

## Description

The **FlushIntention** enumeration specifies when to flush the queue of graphics operations.

## Constants

### `FlushIntentionFlush:0`

When passed to the [Graphics::Flush](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-flush) method, specifies that pending rendering operations are executed as soon as possible. The **Graphics::Flush** method is not synchronized with the completion of the rendering operations and might return before the rendering operations are completed.

### `FlushIntentionSync`

When passed to the [Graphics::Flush](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-flush) method, specifies that pending rendering operations are executed as soon as possible. The **Graphics::Flush** method is synchronized with the completion of the rendering operations; that is, it will not return until after the rendering operations are completed.