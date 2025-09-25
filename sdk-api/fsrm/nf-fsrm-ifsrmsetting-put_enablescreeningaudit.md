# IFsrmSetting::put_EnableScreeningAudit

## Description

Retrieves or sets a value that determines whether FSRM keeps audit records of the file screen
violations.

This property is read/write.

## Parameters

## Remarks

The records are included in a File Screen Audit report. An audit record contains the following items:

* Folder path
* Id
* Blocked file group name
* File screen mode
* Time stamp of when the violation occurred
* The name of the process image that generated the prohibited IO, if available
* The SID of the user principal that issued the prohibited IO, if available
* The full path of the prohibited file
* The server name

If this property is false and a report specifies the
**FsrmReportType_FileScreenAudit** report type, the report will succeed but will not
contain any audit information (or will contain audits that were done before auditing was disabled).

#### Examples

For an example, see [IFsrmSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmsetting).

## See also

[FsrmSetting](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmsetting)

[IFsrmSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmsetting)