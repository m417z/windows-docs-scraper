# USBCAMD_Debug_LogEntry function

## Description

The **USBCAMD_Debug_LogEntry** function is called by the camera minidriver to log debugging information to a file.

## Parameters

### `Name` [in]

Pointer to a **NULL**-terminated string containing the name of the file to write the log entry to.

### `Info1` [in]

Specifies the first information value to be written to the log file.

### `Info2` [in]

Specifies the second information value to be written to the log file.

### `Info3` [in]

Specifies the third information value to be written to the log file.

## Remarks

The original USBCAMD does not call **USBCAMD_Debug_LogEntry**.