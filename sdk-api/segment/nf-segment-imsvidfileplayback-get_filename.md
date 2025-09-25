# IMSVidFilePlayback::get_FileName

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_FileName** method retrieves the name of the file to play.

## Parameters

### `FileName` [out]

Pointer to a variable that receives the file name.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The caller must release the returned string, using the **CoTaskMemFree** function.

## See also

[IMSVidFilePlayback Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidfileplayback)