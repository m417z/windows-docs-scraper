# VisualMutationType enumeration

## Description

Defines constants that specify whether the element was added to or removed from the live visual tree.

## Constants

### `Add:0`

The child element was added to the visual tree of the parent element.

### `Remove`

The child element was removed from the visual tree of the parent element.

## Remarks

**VisualMutationType** is used by [IVisualTreeServiceCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ivisualtreeservicecallback) to indicate to the callback
whether the element is entering or leaving the live visual tree.