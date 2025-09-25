# IGPMStarterGPO::CopyTo

## Description

The **CopyTo** method copies the current Starter GPO and returns a pointer to the copy of the Starter GPO. The method copies all the contents of the Starter GPO but creates the new Starter GPO with the default new Starter GPO delegation settings. Copying a system Starter GPO creates a new custom Starter GPO.

## Parameters

### `pvarNewDisplayName` [in, optional]

Display name to be put on the copied Starter GPO. A display name is assigned if the **VARIANT** structure does not contain a **BSTR**, or if *pvarNewDisplayName* is **NULL**.

### `pvarGPMProgress` [in, optional]

Specifies a pointer to an
[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of the copy operation. This parameter must be **NULL** if the client does not receive asynchronous notifications.

### `pvarGPMCancel` [in, optional]

Receives a pointer to an
[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the copy operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Address of a pointer to the
[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface that represents the result of the copy operation. That interface contains pointers to an
[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) interface and an
[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface.

## Return value

Returns **S_OK** if successful. Returns a failure code if an error occurs.

For more information, see the following Remarks section.

## Remarks

Note that you must check the code returned by the
[IGPMResult::OverallStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmresult-overallstatus) method as well as the one returned by this method to determine whether or not the operation succeeded.
**OverallStatus** returns an overall status code for the operation. If no error occurred during the operation, it returns a success code; otherwise it returns a failure code.

## See also

[IGPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo)