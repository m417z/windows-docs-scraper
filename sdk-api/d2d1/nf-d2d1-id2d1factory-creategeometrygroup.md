# ID2D1Factory::CreateGeometryGroup

## Description

Creates an [ID2D1GeometryGroup](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometrygroup), which is an object that holds other geometries.

## Parameters

### `fillMode`

Type: **[D2D1_FILL_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_fill_mode)**

A value that specifies the rule that a composite shape uses to determine whether a given point is part of the geometry.

### `geometries` [in]

Type: **[ID2D1Geometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometry)****

An array containing the geometry objects to add to the geometry group. The number of elements in this array is indicated by the *geometriesCount* parameter.

### `geometriesCount`

Type: **UINT**

The number of elements in *geometries*.

### `geometryGroup` [out]

Type: **[ID2D1GeometryGroup](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometrygroup)****

When this method returns, contains the address of a pointer to the geometry group created by this method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

Geometry groups are a convenient way to group several geometries simultaneously so all figures of several distinct geometries are concatenated into one. To create a [ID2D1GeometryGroup](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometrygroup) object, call the **CreateGeometryGroup** method on the [ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory) object, passing in the *fillMode* with possible values of [D2D1_FILL_MODE_ALTERNATE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_fill_mode) (alternate) and **D2D1_FILL_MODE_WINDING**, an array of geometry objects to add to the geometry group, and the number of elements in this array.

## Examples

The following code example first declares an array of geometry objects. These objects are four concentric circles that have the following radii: 25, 50, 75, and 100. Then call the **CreateGeometryGroup** on the [ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory) object, passing in [D2D1_FILL_MODE_ALTERNATE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_fill_mode), an array of geometry objects to add to the geometry group, and the number of elements in this array.

```cpp
ID2D1Geometry *ppGeometries[] =
{
    m_pEllipseGeometry1,
    m_pEllipseGeometry2,
    m_pEllipseGeometry3,
    m_pEllipseGeometry4
};

hr = m_pD2DFactory->CreateGeometryGroup(
    D2D1_FILL_MODE_ALTERNATE,
    ppGeometries,
    ARRAYSIZE(ppGeometries),
    &m_pGeoGroup_AlternateFill
    );

if (SUCCEEDED(hr))
{
    hr = m_pD2DFactory->CreateGeometryGroup(
        D2D1_FILL_MODE_WINDING,
        ppGeometries,
        ARRAYSIZE(ppGeometries),
        &m_pGeoGroup_WindingFill
        );
}

```

The following illustration shows the results of rendering the two group geometries from the example.

![Illustration of two sets of four concentric circles, one with the second and fourth rings filled and one with all rings filled](https://learn.microsoft.com/windows/win32/api/d2d1/images/create_geometry_group.png)

## See also

[Geometries Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-geometries-overview)

[ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)