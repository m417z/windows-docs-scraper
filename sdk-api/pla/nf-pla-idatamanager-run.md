# IDataManager::Run

## Description

Manually runs the data manager.

## Parameters

### `Steps` [in]

Determines whether the folder actions and resource policies are applied and how to generate the report. For possible steps, see the [DataManagerSteps](https://learn.microsoft.com/windows/win32/api/pla/ne-pla-datamanagersteps) enumeration.

### `bstrFolder` [in]

The folder under the [IDataCollectorSet::RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath) property that contains the files used to generate the report. If **NULL**, PLA uses all the files in the collection. This folder is used only if the *Steps* parameter includes **plaCreateReport** or **plaRunRules**.

### `Errors` [out]

An [IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap) interface that you use to retrieve any errors that occurred. The value map can contain the list of directories where errors were encountered, along with the error codes. The [IValueMap::Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_count) property is zero if there were no errors.

## Return value

Returns S_OK if successful.

## Remarks

Data management runs in the current process and blocks until the data management steps complete.

To automatically run the data manager when the data collector set finishes running, set the [IDataManager::Enabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_enabled) property to VARIANT_TRUE.

## See also

[IDataManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatamanager)