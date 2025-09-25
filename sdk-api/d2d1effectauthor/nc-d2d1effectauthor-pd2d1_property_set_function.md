# PD2D1_PROPERTY_SET_FUNCTION callback function

## Description

Sets a property on an effect.

## Parameters

### `effect` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for the effect on which the property will be set.

### `data` [in]

A pointer to the data to be set on the property.

### `dataSize`

The number of bytes in the property set by the function.

## Return value

Returns S_OK if successful; otherwise, returns an **HRESULT** error code.

## Remarks

Supply a **PD2D1_PROPERTY_SET_FUNCTION** function pointer to the **setFunction** member of a [D2D1_PROPERTY_BINDING](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_property_binding) structure to specify the function that Direct2D uses to set data for a property.

## See also

[D2D1_PROPERTY_BINDING](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_property_binding)