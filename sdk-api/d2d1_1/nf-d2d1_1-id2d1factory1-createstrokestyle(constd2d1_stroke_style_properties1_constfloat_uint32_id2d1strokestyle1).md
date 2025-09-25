# ID2D1Factory1::CreateStrokeStyle(const D2D1_STROKE_STYLE_PROPERTIES1,const FLOAT,UINT32,ID2D1StrokeStyle1)

## Description

Creates a [ID2D1StrokeStyle1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1strokestyle1) object.

## Parameters

### `strokeStyleProperties` [in]

Type: **const [D2D1_STROKE_STYLE_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_stroke_style_properties1)***

The stroke style properties to apply.

### `dashes` [in]

Type: **const [FLOAT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-abcfloat)***

An array of widths for the dashes and gaps.

### `dashesCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_uint64_description)**

The size of the dash array.

### `strokeStyle` [out]

Type: **const [ID2D1StrokeStyle1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1strokestyle1)****

When this method returns, contains the address of a pointer to the newly created stroke style.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## Remarks

It is valid to specify a dash array only if D2D1_DASH_STYLE_CUSTOM is also specified.

## See also

[ID2D1Factory1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1factory1)

[ID2D1StrokeStyle1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1strokestyle1)