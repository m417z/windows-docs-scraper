# BranchOfficeJobDataError structure

## Description

This structure contains the necessary data for logging a branch office job failure event on a remote server. This is based on standard job-related data available to the spooler.

## Members

### `LastError`

Specifies the LastError at the time the event was logged.

### `pDocumentName`

Specifies the name of the printed document.

### `pUserName`

Specifies the user who submitted the job.

### `pPrinterName`

Specifies the name of the print connection.

### `pDataType`

Specifies the data type of the job.

### `TotalSize`

Specifies the 64-bit size of the job.

### `PrintedSize`

Specifies the 64-bit size of the job.

### `TotalPages`

Specifies the total number of pages in the job.

### `PrintedPages`

Specifies the number of pages currently printed.

### `pMachineName`

Specifies the name of the client machine printing the job.

### `pJobError`

Specifies the failure code for a JOB_ERROR event.

### `pErrorDescription`

Specifies the text description of the error, if available.