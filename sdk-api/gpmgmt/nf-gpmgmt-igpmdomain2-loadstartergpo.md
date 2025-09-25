# IGPMDomain2::LoadStarterGPO

## Description

Opens a Starter Group Policy object (GPO) cabinet (CAB) file and imports it into the domain.

## Parameters

### `bstrLoadFile` [in]

Required. Name of the CAB file to load. Use a null-terminated string.

### `bOverwrite` [in]

Determines whether to overwrite any existing versions of the Starter GPO. Loading a Starter GPO from a CAB retains the ID of the original Starter GPO used to create the CAB, therefore it is possible to have a version of the Starter GPO already existing in the domain when the **LoadStarterGPO** method is called.

#### VARIANT_FALSE

Do not overwrite an existing Starter GPO.

#### VARIANT_TRUE

Overwrite an existing Starter GPO.

### `pvarGPMProgress` [in, optional]

Specifies a pointer to an
[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of the copy operation. This parameter must be **NULL** if the client does not receive asynchronous notifications.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an
[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the copy operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Address of a pointer to the
[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface that represents the result of the load operation. That interface contains pointers to an
[IGPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) interface and to an
[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

## See also

[IGPMDomain2](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain2)