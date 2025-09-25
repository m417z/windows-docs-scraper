# IMSVidCtl::get_State

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_State** method retrieves the state of the filter graph.

## Parameters

### `lState` [out]

Receives a member of the [MSVidCtlStateList](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/ne-msvidctl-msvidctlstatelist) enumeration.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | NULL pointer argument. |

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)