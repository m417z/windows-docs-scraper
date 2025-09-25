# IStreamBufferRecComp::GetCurrentLength

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetCurrentLength** method retrieves the length of the target file.

## Parameters

### `pcSeconds` [out]

Pointer to a variable that receives the current length, in seconds.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

To get accurate updates, you can call this method continually from one thread while another thread performs append operations.

## See also

[IStreamBufferRecComp Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferreccomp)