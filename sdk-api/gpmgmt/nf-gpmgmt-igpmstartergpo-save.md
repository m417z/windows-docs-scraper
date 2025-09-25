# IGPMStarterGPO::Save

## Description

Saves all Starter GPO settings into a single CAB file. Optionally the user may specify to save a custom Starter GPO as a system Starter GPO.

## Parameters

### `bstrSaveFile` [in]

Name of the file to which the Starter GPO should be saved. Use null-terminated string.

### `bOverwrite` [in]

Boolean value that determines whether the file should be overwritten, if it exists.

### `bSaveAsSystem` [in]

Boolean value that specifies whether to convert the Starter GPO into a system template as part of the save. By default, the value is **VARIANT_FALSE**, save as a system Starter GPO. This option must be VARIANT_FALSE if the Starter GPO being saved is a system Starter GPO; entering VARIANT_TRUE for a system Starter GPO will return an invalid argument error.

### `bstrLanguage` [in, optional]

Specifies the MUI language code all the language specific strings of the custom Starter GPO will be exported during the save. The custom Starter GPO strings are converted into MUI resources without performing any language checks on the strings. If bSaveAsSystem is VARIANT_FALSE this parameter is ignored. If this parameter is **NULL**, the user's current language code is used.

### `bstrAuthor` [in, optional]

Specifies the Author property of the new system Starter GPO. If bSaveAsSystem is VARIANT_FALSE this parameter is ignored.

### `bstrProduct` [in, optional]

Specifies the Product property of the new system Starter GPO. If bSaveAsSystem is VARIANT_FALSE this parameter is ignored

### `bstrUniqueID` [in, optional]

Specifies the ID property of the new system Starter GPO. If the parameter is **NULL** a new unique ID will be generated. If bSaveAsSystem is VARIANT_FALSE this parameter is ignored.

### `bstrVersion` [in, optional]

Specifies the Starter GPO version of the new system Starter GPO. The format of the string must be 4 digits-dot-5 digits. If the value is **NULL** the version is set to 1.0. If bSaveAsSystem is VARIANT_FALSE this parameter is ignored

### `pvarGPMProgress` [in, optional]

Pointer to an [IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress) interface that allows the client to receive status notifications about the progress of the copy operation. If not **NULL**, the call to [GenerateReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmbackup-generatereport) is handled asynchronously and *pvarGPMCancel* receives a pointer to an [IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface. If this parameter is **NULL** the call to **GenerateReport** is handled synchronously. The *pvarGPMProgress* parameter must be **NULL** if the client should not receive asynchronous notifications.

### `pvarGPMCancel` [out, optional]

Receives a pointer to an [IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel) interface that the client can use to cancel the copy operation. This parameter is not returned if *pvarGPMProgress* is **NULL**.

### `ppIGPMResult` [out]

Pointer to an [IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult). The Result property contains a string representing the GUID of the saved Starter GPO. If bSaveAsSystem is **VARIANT_TRUE**, the Starter GPO will be saved with a new GUID as specified by bstrUniqueID. The Status property contains a reference to an [IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection).

## Return value

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## See also

[IGPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo)