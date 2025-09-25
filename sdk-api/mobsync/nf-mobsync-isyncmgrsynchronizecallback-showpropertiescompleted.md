# ISyncMgrSynchronizeCallback::ShowPropertiesCompleted

## Description

Called by the registered application's handler before or after its
[ShowProperties](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showproperties) operation is completed.

## Parameters

### `hr` [in]

Type: **HRESULT**

Whether the [ShowProperties](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showproperties) was successful.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Call was completed successfully. |

## Remarks

It is acceptable for the registered application's handler to call this method before returning from the [ShowProperties](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showproperties) method.

This method should not be called if the registered application's handler does not return a success code from the [ShowProperties](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showproperties) method.

## See also

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)

[ShowProperties](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showproperties)