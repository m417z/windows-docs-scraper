# IMSVidFeatures::Remove

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Remove** method removes an item from the collection.

## Parameters

### `v` [in]

**VARIANT** that specifies the index of the item to remove.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADINDEX** | The index is out of range. |
| **DISP_E_TYPEMISMATCH** | Wrong **VARIANT** type. |
| **E_ACCESSDENIED** | The collection is read-only; cannot remove any items. |
| **E_UNEXPECTED** | Unexpected error. |

## Remarks

The *v* parameter must be a **VARIANT** that contains an integer type (VT_I4). The valid range is from 0 to `IMSVidFeatures::get_Count` - 1.

## See also

[IMSVidFeatures Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidfeatures)

[IMSVidFeatures::Add](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidfeatures-add)