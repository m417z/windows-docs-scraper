# IGPMStarterGPO::GenerateReportToFile

## Description

The **GenerateReportToFile** method gets the report for the GPO and saves it to a file at a specified path.

## Parameters

### `gpmReportType` [in]

Specifies whether the report is in XML or HTML.

### `bstrTargetFilePath` [in]

Binary string that contains the path to the file where the report is being saved. Use null-terminated string.

### `ppIGPMResult` [out]

Pointer to an [IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface. The **Status** property contains a reference to an [IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection).

**Note** The value of the **Result** property of the [IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface is indeterminate and should not be relied upon.

## Return value

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## See also

[IGPMStarterGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstartergpo)