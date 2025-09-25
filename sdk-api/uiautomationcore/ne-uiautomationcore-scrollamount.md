# ScrollAmount enumeration

## Description

Contains values that specify the direction and distance to scroll.

## Constants

### `ScrollAmount_LargeDecrement:0`

Scrolling is done in large decrements, equivalent to pressing the PAGE UP key or clicking on a blank part of a scroll bar. If one page up is not a relevant amount for the control and no scroll bar exists, the value represents an amount equal to the current visible window.

### `ScrollAmount_SmallDecrement:1`

Scrolling is done in small decrements, equivalent to pressing an arrow key or clicking the arrow button on a scroll bar.

### `ScrollAmount_NoAmount:2`

No scrolling is done.

### `ScrollAmount_LargeIncrement:3`

Scrolling is done in large increments, equivalent to pressing the PAGE DOWN or PAGE UP key or clicking on a blank part of a scroll bar.
If one page is not a relevant amount for the control and no scroll bar exists, the value represents an amount equal to the current visible window.

### `ScrollAmount_SmallIncrement:4`

Scrolling is done in small increments, equivalent to pressing an arrow key or clicking the arrow
button on a scroll bar.

## See also

[IScrollProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iscrollprovider)