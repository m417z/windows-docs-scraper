# IStreamBufferSink2::UnlockProfile

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **UnlockProfile** method unlocks the Stream Buffer Sink filter's profile. After the profile is unlocked, you can change the name of the stub file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The profile is not currently locked. |
| **S_OK** | The method succeeded. |

## Remarks

The filter graph must be stopped when you call this method. If the recording session has not been started, this method invalidates the recording. To re-create the recording, call [IStreamBufferSink::LockProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambuffersink-lockprofile) again. If the profile is not already locked, the **UnlockProfile** method has no effect and returns S_FALSE.

If the graph is running, stopping the graph automatically unlocks the profile without the need to call **UnlockProfile**.

## See also

[IStreamBufferSink2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambuffersink2)