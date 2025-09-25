# IMSVidAudioRendererDevices::get_Item

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Item** method retrieves the specified item from the collection.

## Parameters

### `v` [in]

**VARIANT** that specifies the index of the item to retrieve.

### `pDB` [out]

Address of a variable that receives an [IMSVidAudioRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorenderer) interface pointer.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADINDEX** | The index is out of range. |
| **DISP_E_TYPEMISMATCH** | Wrong **VARIANT** type. |
| **E_POINTER** | NULL pointer argument. |
| **E_UNEXPECTED** | Unexpected error. |

## Remarks

The *v* parameter must be a **VARIANT** that contains an integer type (VT_I4). The valid range is from 0 to `IMSVidAudioRendererDevices::get_Count` - 1.

If the method succeeds, the [IMSVidAudioRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorenderer) interface has an outstanding reference count. The caller must release the interface.

## See also

[IMSVidAudioRendererDevices Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorendererdevices)