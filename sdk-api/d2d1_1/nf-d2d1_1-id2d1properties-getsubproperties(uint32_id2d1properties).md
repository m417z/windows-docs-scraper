# ID2D1Properties::GetSubProperties

## Description

Gets the sub-properties of the provided property by index.

## Parameters

### `index`

Type: **UINT32**

The index of the sub-properties to be retrieved.

### `subProperties` [out]

Type: **[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)****

When this method returns, contains the address of a pointer to the sub-properties.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| D2DERR_NO_SUBPROPERTIES | The specified property does not exist. |

## Remarks

If there are no sub-properties, *subProperties* will be **NULL**, and **D2DERR_NO_SUBPROPERTIES** will be returned.

## See also

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)