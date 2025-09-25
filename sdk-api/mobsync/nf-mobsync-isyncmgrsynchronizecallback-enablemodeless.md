# ISyncMgrSynchronizeCallback::EnableModeless

## Description

Called by the registered application before and after any dialog boxes are displayed from within the [PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync) and
[Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize) methods.

## Parameters

### `fEnable` [in]

Type: **BOOL**

**TRUE** if the registered application is requesting permission to display a dialog box or **FALSE** if the registered application has finished displaying a dialog box.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Continue the synchronization. |
| **S_FALSE** | The dialog box should not be displayed. |

## Remarks

To request permission to display a dialog box, the registered application first calls **ISyncMgrSynchronizeCallback::EnableModeless** with *fEnable* set to **TRUE**. If S_OK is returned, the registered application may display the dialog box. Once the dialog box has been displayed, the registered application must call **ISyncMgrSynchronizeCallback::EnableModeless** with *fEnable* set to **FALSE** to notify SyncMgr that other items may now display user interface elements.

## See also

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)

[PrepareForSync](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-prepareforsync)

[Synchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-synchronize)