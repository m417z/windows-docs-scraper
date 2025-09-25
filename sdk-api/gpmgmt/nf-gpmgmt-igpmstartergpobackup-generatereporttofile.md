## Description

The [GenerateReportToFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmbackup-generatereporttofile) gets the report for the backup Starter GPO and saves it to a file at a specified path.

## Parameters

### `gpmReportType` [in]

Specifies whether the report is in XML or HTML.

### `bstrTargetFilePath` [in]

Binary string that contains the path to the file where the report is being saved. Use null-terminated string.

### `ppIGPMResult` [out]

Pointer to an [IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface. The **Status** property contains a reference to an [IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection).

**Note** The value of the **Result** property is indeterminate and should not be relied upon.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

**Note** The value of the **Result** property is indeterminate and should not be relied upon.

### VB

Returns a reference to a [GPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) object.

**Note** The value of the **Result** property is indeterminate and should not be relied upon.

## See also

[IGPMBackupDirEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackupdirex)

[IGPMStarterGPOBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpobackup)

[IGPMStarterGPOBackupCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpobackupcollection)