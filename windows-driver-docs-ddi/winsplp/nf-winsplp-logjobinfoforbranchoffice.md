# LogJobInfoForBranchOffice function

## Description

Allows Branch Office clients to send job events to the host print server.

## Parameters

### `hPrinter` [in]

Specifies a handle to the CSR printer.

### `pJobDataContainer` [in]

Specifies a pointer to an array of [BranchOfficeJobData](https://learn.microsoft.com/dotnet/core/rid-catalog) structures, containing the events to be logged.

## Return value

Indicates success or failure.