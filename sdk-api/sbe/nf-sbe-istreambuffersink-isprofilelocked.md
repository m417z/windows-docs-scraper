# IStreamBufferSink::IsProfileLocked

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies only to Windows XP Service Pack 1 or later.

The **IsProfileLocked** method queries whether the Stream Buffer Sink filter's profile is locked.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The profile is locked. |
| **S_FALSE** | The profile is not locked. |
| **E_FAIL** | The method failed. |

## Remarks

When the filter's profile is locked, the number of streams and their media types are fixed. For more information, see [IStreamBufferSink::LockProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambuffersink-lockprofile).

## See also

[IStreamBufferSink Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambuffersink)