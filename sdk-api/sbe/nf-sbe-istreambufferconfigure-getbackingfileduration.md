# IStreamBufferConfigure::GetBackingFileDuration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetBackingFileDuration** method retrieves the duration of each backing file.

## Parameters

### `pdwSeconds` [out]

Pointer to a variable that receives the file duration, in seconds.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IStreamBufferConfigure Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure)