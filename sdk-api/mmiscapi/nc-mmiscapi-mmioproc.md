# MMIOPROC callback function

## Description

The **MMIOProc** function is a custom input/output (I/O) procedure installed by the [mmioInstallIOProc](https://learn.microsoft.com/previous-versions/dd757323(v=vs.85)) function. **MMIOProc** is a placeholder for the application-defined function name. The address of this function can be specified in the callback-address parameter of **mmioInstallIOProc**.

## Parameters

### `lpmmioinfo`

Points to an [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure containing information about the open file.

The I/O procedure must maintain the **lDiskOffset** member in this structure to indicate the file offset to the next read or write location. The I/O procedure can use the **adwInfo**[] member to store state information. The I/O procedure should not modify any other members of the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure.

### `uMsg`

Specifies a message indicating the requested I/O operation. Messages that can be received include [MMIOM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mmiom-open), [MMIOM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mmiom-close), [MMIOM_READ](https://learn.microsoft.com/windows/desktop/Multimedia/mmiom-read), [MMIOM_SEEK](https://learn.microsoft.com/windows/desktop/Multimedia/mmiom-seek), [MMIOM_WRITE](https://learn.microsoft.com/windows/desktop/Multimedia/mmiom-write), and [MMIOM_WRITEFLUSH](https://learn.microsoft.com/windows/desktop/Multimedia/mmiom-writeflush).

### `lParam1`

Specifies an application-defined parameter for the message.

### `lParam2`

Specifies an application-defined parameter for the message.

## Return value

The return value depends on the message specified by *uMsg*. If the I/O procedure does not recognize a message, it should return zero.

## Remarks

The four-character code specified by the **fccMMIOProc** member in the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure associated with a file identifies a file name extension for a custom storage system. When an application calls [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) with a file name such as "one.xyz+two", the I/O procedure associated with the four-character code "XYZ" is called to open the "two" element of the file "one.xyz".

The [mmioInstallIOProc](https://learn.microsoft.com/previous-versions/dd757323(v=vs.85)) function maintains a separate list of installed I/O procedures for each Windows-based application. Therefore, different applications can use the same I/O procedure identifier for different I/O procedures without conflict. However, installing an I/O procedure globally enables any process to use the procedure.

If an application calls [mmioInstallIOProc](https://learn.microsoft.com/previous-versions/dd757323(v=vs.85)) more than once to register the same I/O procedure, then it must call **mmioInstallIOProc** to remove the procedure once for each time it installed the procedure.

[mmioInstallIOProc](https://learn.microsoft.com/previous-versions/dd757323(v=vs.85)) will not prevent an application from installing two different I/O procedures with the same identifier, or installing an I/O procedure with one of the predefined identifiers ("DOS ", "MEM "). The most recently installed procedure takes precedence, and the most recently installed procedure is the first one to be removed.

When searching for a specified I/O procedure, local procedures are searched first, then global procedures.