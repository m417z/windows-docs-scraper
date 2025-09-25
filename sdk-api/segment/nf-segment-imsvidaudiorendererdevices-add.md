# IMSVidAudioRendererDevices::Add

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Add** method adds an audio renderer to the collection.

## Parameters

### `pDB` [in]

Pointer to the audio renderer's [IMSVidAudioRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorenderer) interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ACCESSDENIED** | The collection is read-only; cannot add any items. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | NULL pointer argument. |

## See also

[IMSVidAudioRendererDevices Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorendererdevices)