# BranchOfficeJobDataPrinted structure

## Description

Contains the necessary data for logging a branch office job completed event on a remote server. This is based on standard job-related data available to the spooler.

## Members

### `Status`

Specifies the current status, or the failure code for a JOB_ERROR event.

### `pDocumentName`

Specifies the name of the printed document.

### `pUserName`

Specifies the user who submitted the job.

### `pMachineName`

Specifies the name of the client machine printing the job

### `pPrinterName`

Specifies the name of the print connection.

### `pPortName`

Specifies the name of the port the job printed on.

### `Size`

Specifies the 64-bit size of the job.

### `TotalPages`

Specifies the total number of pages in the job.