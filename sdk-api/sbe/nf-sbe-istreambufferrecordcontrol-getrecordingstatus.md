# IStreamBufferRecordControl::GetRecordingStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetRecordingStatus** method retrieves the status of the recording.

## Parameters

### `phResult` [out]

Pointer to a variable that receives an **HRESULT** value. The **HRESULT** value indicates the current status of writing or closing the file. This parameter can be **NULL**.

### `pbStarted` [out]

Pointer to a variable that receives a Boolean value, indicating whether the recording has started,

| Value | Description |
| --- | --- |
| **TRUE** | The recording has started. |
| **FALSE** | The recording has not started. |

This parameter can be **NULL**.

### `pbStopped` [out]

Pointer to a variable that receives a Boolean value, indicating whether recording has been stopped.

| Value | Description |
| --- | --- |
| **TRUE** | The recording has stopped. |
| **FALSE** | The recording has not stopped, or has not started yet. |

This parameter can be **NULL**.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method reports the status of the **Start** and **Stop** methods, which themselves are asynchronous.

## See also

[IStreamBufferRecordControl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferrecordcontrol)