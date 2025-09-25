# IMSVidXDS::get_ChannelChangeInterface

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

**Note**This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 or later.

The **get_ChannelChangeInterface** method retrieves a pointer to an interface that raises an event when the channel is changed.

## Parameters

### `punkCC` [out]

Receives a pointer to the **IUnknown** interface. The caller must release the interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | Success. |

## See also

[IMSVidXDS Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidxds)