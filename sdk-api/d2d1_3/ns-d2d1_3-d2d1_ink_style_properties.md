# D2D1_INK_STYLE_PROPERTIES structure

## Description

Defines the general pen tip shape and the transform used in an [ID2D1InkStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1inkstyle) object.

## Members

### `nibShape`

The pre-transform shape of the nib (pen tip) used to draw a given ink object.

### `nibTransform`

The transform applied to the nib. Note that the translation components of the transform matrix are ignored for the purposes of rendering.