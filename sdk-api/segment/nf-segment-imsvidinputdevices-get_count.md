# IMSVidInputDevices::get_Count

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Count** method retrieves the number of items in the collection.

## Parameters

### `lCount` [out]

Pointer to a variable that receives the number of items.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | NULL pointer argument. |

## See also

[IMSVidInputDevices Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevices)