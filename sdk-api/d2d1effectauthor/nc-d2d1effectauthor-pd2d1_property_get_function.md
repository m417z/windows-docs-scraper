# PD2D1_PROPERTY_GET_FUNCTION callback function

## Description

Gets a property from an effect.

## Parameters

### `effect` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for the effect on which the property will be retrieved.

### `data` [out]

A pointer to a variable that stores the data that this function retrieves on the property.

### `dataSize`

The number of bytes in the property to retrieve.

### `actualSize` [out, optional]

A optional pointer to a variable that stores the actual number of bytes retrieved on the property. If not used, set to **NULL**.

## Return value

Returns S_OK if successful; otherwise, returns an **HRESULT** error code.

## Remarks

Supply a **PD2D1_PROPERTY_GET_FUNCTION** to the **getFunction** member of a [D2D1_PROPERTY_BINDING](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_property_binding) structure to specify the function that Direct2D uses to get data for a property.

## See also

[D2D1_PROPERTY_BINDING](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_property_binding)