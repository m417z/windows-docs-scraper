## Description

Gets the report for a GPO and then saves the report to a file in a specified path.

## Parameters

### `gpmReportType` [in]

Specifies whether the report is in XML or HTML.

### `bstrTargetFilePath` [in]

Binary string that contains the path of the file in which the report is being saved. Use a null-terminated string.

### `ppIGPMResult` [out]

Pointer to an [IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface. The **Status** property contains a reference to an [IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection).

**Note** The value of the **Result** property of the [IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult) interface is indeterminate and should not be relied upon.

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

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)