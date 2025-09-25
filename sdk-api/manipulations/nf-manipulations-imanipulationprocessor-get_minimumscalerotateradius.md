# IManipulationProcessor::get_MinimumScaleRotateRadius

## Description

Specifies how large the distance contacts on a scale or rotate gesture need to be to trigger manipulation.

This property is read/write.

## Parameters

## Remarks

**Note** This property is set in centipixels (100ths of a pixel).

Setting this value will make the manipulation processor ignore gestures that have too small of a radius.
This is useful if you want to prevent a user from manipulating an object to too small of a radius. For example,
if you are using a manipulation processor with a circle and want the ensure that it maintains a radius greater
than 100 pixels, you would set this value to 10000.

#### Examples

```cpp
pManip->put_MinimumScaleRotateRadius(4000.0f);

```

## See also

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)