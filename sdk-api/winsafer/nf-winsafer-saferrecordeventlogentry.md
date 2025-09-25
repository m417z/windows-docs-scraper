# SaferRecordEventLogEntry function

## Description

The **SaferRecordEventLogEntry** function saves messages to an event log.

## Parameters

### `hLevel` [in]

SAFER_LEVEL_HANDLE that contains the details of the rule to send to the event log.

### `szTargetPath` [in]

Path of the file that attempted to run.

### `lpReserved`

Reserved for future use. This parameter should be set to **NULL**.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If [SaferIdentifyLevel](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-saferidentifylevel) returns a SAFER_LEVEL_HANDLE with a LevelId that is anything other than SAFER_LEVELID_FULLYTRUSTED (0x40000), **SaferRecordEventLogEntry** can be called to facilitate troubleshooting. For example, clicking a button in excel.exe might attempt to launch another process that is not fully trusted. This might display an obscure error message because the program remapped the error returned from CreateProcess. To ease troubleshooting, some Safer functions call **SaferRecordEventLogEntry** to send an event to the event log.