# ID2D1EffectImpl::PrepareForRender

## Description

Prepares an effect for the rendering process.

## Parameters

### `changeType`

Type: **[D2D1_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_change_type)**

Indicates the type of change the effect should expect.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

This method is called by the renderer when the effect is within an effect graph that is drawn.

 The method will be called:

* If the effect has been initialized but has not previously been drawn.
* If an effect property has been set since the last draw call.
* If the context state has changed since the effect was last drawn.

The method will not otherwise be called. The transforms created by the effect will be called to handle their input and output rectangles for every draw call.

Most effects defer creating any resources or specifying a topology until this call is made. They store their properties and map them to a concrete set of rendering techniques when first drawn.

#### Examples

An effect normally waits until it is rendered before snapping its current state and applying it to any transforms it has encapsulated.

```cpp
class CMyTransform : public ID2D1DrawTransform
{
public:

    // Transform methods omitted.

    HRESULT PrepareForRender(FLOAT radius);
};

class CEffectImplementation : public ID2D1EffectImpl
{
public:

    void SetRadius(FLOAT radius) { _radius = radius; }

    IFACEMETHODIMP PrepareForRender(D2D1_CHANGE_TYPE /*type*/)
    {
        // Send the radius to the transform and ask it to render.
        return _pMyTransform->PrepareForRender(_radius);
    }

private:

    CMyTransform *_pMyTransform;
    FLOAT _radius;
};

```

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1EffectImpl](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectimpl)