# IFsrmClassificationManager::put_Logging

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

The types of logging to perform when running the classification rules.

This property is read/write.

## Parameters

## Remarks

The log file for the **FsrmClassificationLoggingFlags_ClassificationsInLogFile** and
**FsrmClassificationLoggingFlags_ErrorsInLogFile** logging options are stored in the
reports directory. The name of the
**FsrmClassificationLoggingFlags_ClassificationsInLogFile** log file is
"*ClassifierName*-*FsrmServerName(FQDN)*-*TimeStamp*.xml".
The log file contains one entry per property assignment to a specific file. Each log entry specifies the:

* File name (full path)
* Property
* Value assigned
* Rule applied
* Result (whether the classification succeeded)

The name of the **FsrmClassificationLoggingFlags_ErrorsInLogFile** log file is
"*ClassifierName**Errors*-*FQDNServerName*-*TimeStamp*.xml".
The log file contains one entry per error. Each log entry specifies the:

* Error code
* File name (full path)
* Property
* Rule applied

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)