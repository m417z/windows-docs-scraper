# IFsrmClassificationManager::WaitForClassificationCompletion

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

Waits for the specified period of time or until classification has finished running.

## Parameters

### `waitSeconds` [in]

The number of seconds to wait for classification and the reports to complete. The method returns when the
period expires or classification and the reports complete. To wait indefinitely, set the value to
–1. The value must be in the range from –1 through 2,147,483.

### `completed` [out]

Is **VARIANT_TRUE** if the reports completed; otherwise,
**VARIANT_FALSE**.

## Return value

The method returns the following return values.

## Remarks

To run the classification, call the
[IFsrmClassificationManager::RunClassification](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-runclassification)
method.

After
**WaitForClassificationCompletion**
returns, access the
[IFsrmClassificationManager.ClassificationLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-get_classificationlasterror)
property to determine if the reports completed successfully.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager.ClassificationRunningStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-get_classificationrunningstatus)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)