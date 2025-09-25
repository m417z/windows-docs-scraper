# OleDraw function

## Description

Enables drawing objects more easily. You can use it instead of calling [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) directly.

## Parameters

### `unnamedParam1`

TBD

### `unnamedParam2`

TBD

### `unnamedParam3`

TBD

### `unnamedParam4`

TBD

### `unnamedParam5`

TBD

#### - dwAspect [in]

How the object is to be represented. Representations include content, an icon, a thumbnail, or a printed document. Possible values are taken from the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration.

#### - hdcDraw [in]

Device context on which to draw. Cannot be a metafile device context.

#### - lprcBounds [in]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure specifying the rectangle in which the object should be drawn. This parameter is converted to a [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure and passed to [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw).

#### - pUnknown [in]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the view object that is to be drawn.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_BLANK** | No data to draw from. |
| **E_ABORT** | The draw operation was aborted. |
| **VIEW_E_DRAW** | No data to draw from. |
| **OLE_E_INVALIDRECT** | The rectangle is invalid. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |
| **DV_E_NOIVIEWOBJECT** | The object doesn't support the [IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject) interface. |

## Remarks

The OleDraw helper function calls the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method for the object specified (pUnk), asking for an [IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject) interface on that object. Then, **OleDraw** converts the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure to a [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure, and calls [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) as follows:

``` syntax
lpViewObj->Draw(dwAspect,-1,0,0,0,hdcDraw,&rectl,0,0,0);
```

Do not use this function to draw into a metafile because it does not specify the parameter required for drawing into metafiles.

## See also

[IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw)