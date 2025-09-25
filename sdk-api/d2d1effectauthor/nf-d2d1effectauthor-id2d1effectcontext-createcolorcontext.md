# ID2D1EffectContext::CreateColorContext

## Description

Creates a color context from a color space.

If the color space is Custom, the context is initialized from the *profile* and *profileSize* parameters.

If the color space is not Custom, the context is initialized with the profile bytes associated with the color space. The *profile* and *profileSize* parameters are ignored.

## Parameters

### `space`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

The space of color context to create.

### `profile` [in, optional]

Type: **const BYTE***

A buffer containing the ICC profile bytes used to initialize the color context when *space* is [D2D1_COLOR_SPACE_CUSTOM](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space). For other types, the parameter is ignored and should be set to **NULL**.

### `profileSize`

Type: **UINT32**

The size in bytes of *Profile*.

### `colorContext` [out]

Type: **[ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext)****

When this method returns, contains the address of a pointer to a new color context object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)