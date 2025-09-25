# COPYFILE2_COPY_PHASE enumeration

## Description

Indicates the phase of a copy at the time of an error. This is used in the
**Error** structure embedded in the
[COPYFILE2_MESSAGE](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_message) structure.

## Constants

### `COPYFILE2_PHASE_NONE:0`

The copy had not yet started processing.

### `COPYFILE2_PHASE_PREPARE_SOURCE`

The source was being prepared including opening a handle to the source. This phase happens once per stream
copy operation.

### `COPYFILE2_PHASE_PREPARE_DEST`

The destination was being prepared including opening a handle to the destination. This phase happens once
per stream copy operation.

### `COPYFILE2_PHASE_READ_SOURCE`

The source file was being read. This phase happens one or more times per stream copy operation.

### `COPYFILE2_PHASE_WRITE_DESTINATION`

The destination file was being written. This phase happens one or more times per stream copy
operation.

### `COPYFILE2_PHASE_SERVER_COPY`

Both the source and destination were on the same remote server and the copy was being processed remotely.
This phase happens once per stream copy operation.

### `COPYFILE2_PHASE_NAMEGRAFT_COPY`

The copy operation was processing symbolic links and/or reparse points. This phase happens once per file
copy operation.

### `COPYFILE2_PHASE_MAX`

One greater than the maximum value. Valid values for this enumeration will be less than this value.

## Remarks

To compile an application that uses this enumeration, define the **_WIN32_WINNT**
macro as 0x0601 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[COPYFILE2_MESSAGE](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_message)

[CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2)

[File Management Enumerations](https://learn.microsoft.com/windows/desktop/FileIO/file-management-enumerations)