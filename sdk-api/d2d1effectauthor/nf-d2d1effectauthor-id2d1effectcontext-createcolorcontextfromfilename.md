# ID2D1EffectContext::CreateColorContextFromFilename

## Description

Creates a color context by loading it from the specified filename. The profile bytes are the contents of the file specified by *filename*.

## Parameters

### `filename`

Type: **PCWSTR**

The path to the file containing the profile bytes to initialize the color context with.

### `colorContext` [out]

Type: **[ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext)****

When this method returns, contains the address of a pointer to a new color context.

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