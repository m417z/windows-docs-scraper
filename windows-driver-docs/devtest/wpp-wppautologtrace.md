# WppAutoLogTrace function

The WppAutoLogTrace function is for internal use only.

## Parameters

`AutoLogContext`

`MessageLevel`

`MessageFlags`

`MessageGuid`

`MessageNumber`

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

This function is for internal use only.

## Requirements

| Requirement | Value |
| ------ | ------ |
| **Kernel mode library** | WppRecorder.sys |
| **User mode library** | WppRecorderUM.dll |