# IMFContentEnabler::MonitorEnable

## Description

Requests notification when the enabling action is completed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The method succeeded and no action was required. |

## Remarks

If you use a manual enabling action, call this method to be notified when the operation completes. If this method returns S_OK, the content enabler will send an [MEEnablerCompleted](https://learn.microsoft.com/windows/desktop/medfound/meenablercompleted) event when the operation is completed. If the application cancels the operation before completing it, call [IMFContentEnabler::Cancel](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-cancel).

You do not have to call **MonitorEnable** when you use automatic enabling by calling [IMFContentEnabler::AutomaticEnable](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-automaticenable).

## See also

[How to Play Protected Media Files](https://learn.microsoft.com/windows/desktop/medfound/how-to-play-protected-media-files)

[IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler)