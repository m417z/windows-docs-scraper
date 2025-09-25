# IStreamBufferRecComp::Close

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Close** method closes the target file.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

This method is called automatically when the [RecComp](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/reccomp-object) object is released.

## See also

[IStreamBufferRecComp Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferreccomp)