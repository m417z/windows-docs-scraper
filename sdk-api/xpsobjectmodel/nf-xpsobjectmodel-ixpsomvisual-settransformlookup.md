# IXpsOMVisual::SetTransformLookup

## Description

Sets the lookup key name of a shared matrix transform in a resource dictionary.

## Parameters

### `key` [in]

The lookup key name of the matrix transform in the dictionary.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_RESOURCE_KEY** | According to the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), the value of *lookup* is not a valid lookup key string. |
| **XPS_E_INVALID_LOOKUP_TYPE** | The lookup key name in *key* references an object that is not a geometry. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the value passed in *key*. |

## Remarks

After you call **SetTransformLookup**, the local transform is released and [GetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-gettransformlocal) returns a **NULL** pointer in the *matrixTransform* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *transform* by [GetTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-gettransform) | Object that is returned in *matrixTransform* by [GetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-gettransformlocal) | Object that is returned in *key* by [GetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-gettransformlookup) |
| --- | --- | --- | --- |
| [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-settransformlocal) | The local transform that is set by [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-settransformlocal). | The local transform that is set by [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-settransformlocal). | **NULL** pointer. |
| **SetTransformLookup** (this method) | The shared transform that gets retrieved—with a lookup key that matches the key that is set by **SetTransformLookup**—from the resource directory. | **NULL** pointer. | The lookup key that is set by **SetTransformLookup**. |
| Neither [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-settransformlocal) nor **SetTransformLookup** has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))