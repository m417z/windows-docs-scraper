# IStreamBufferConfigure3::SetStartRecConfig

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetStartRecConfig** method specifies whether the [IStreamBufferRecordControl::Start](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferrecordcontrol-start) method automatically stops the current recording.

## Parameters

### `fStartStopsCur` [in]

If **TRUE**, the **Start** method automatically stops the current recording. Otherwise, the **Start** method fails if another recording is in progress. The default value is **FALSE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

By default, if another recording is still in progress, the **IStreamBufferRecordControl::Start** method fails. If the *fStartStopsCur* parameter is **TRUE**, the **Start** method will automatically stop a recording in progress.

## See also

[IStreamBufferConfigure3 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure3)