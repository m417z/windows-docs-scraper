## Description

Gets the index corresponding to the given property name.

## Parameters

### `name` [in]

Type: **PCWSTR**

The name of the property to retrieve.

## Return value

Type: **UINT32**

The index of the corresponding property name.

## Remarks

If the property doesn't exist, then this method returns [D2D1_INVALID_PROPERTY_INDEX](https://learn.microsoft.com/windows/win32/direct2d/direct2d-constants#d2d1_invalid_property_index-uintmax). This reserved value will never map to a valid index, and will cause **NULL** or sentinel values to be returned from other parts of the property interface.

## See also

[D2D1_INVALID_PROPERTY_INDEX](https://learn.microsoft.com/windows/win32/direct2d/direct2d-constants#d2d1_invalid_property_index-uintmax)

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)