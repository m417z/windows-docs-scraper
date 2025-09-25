# IGPM2::InitializeReportingEx

## Description

Sets the location to search for .adm files and the reporting option to determine whether to include comments in the report. This method initializes reporting in an asynchronous manner.

For both Group Policy object (GPO) reporting or Resultant Set of Policy (RSOP) reporting, the Group Policy Management Console (GPMC) searches for and loads .adm files in the following order. First it searches for the specified .adm files in the specified location. Then it searches for any additional .adm files in the default location. Finally it searches the GPO or RSoP for any additional .adm files.

## Parameters

### `bstrAdmPath` [in]

Location to search for .adm files.

### `reportingOptions` [in]

Reporting options. This parameter must be one of the following values.

#### 0

Do not include comments in the report.

#### 1

Include comments in the report.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## See also

[IGPM2](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm2)