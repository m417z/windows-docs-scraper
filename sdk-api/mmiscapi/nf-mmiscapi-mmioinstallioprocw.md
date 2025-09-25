# mmioInstallIOProcW function

## Description

The **mmioInstallIOProc** function installs or removes a custom I/O procedure. This function also locates an installed I/O procedure, using its corresponding four-character code.

## Parameters

### `fccIOProc`

Four-character code identifying the I/O procedure to install, remove, or locate. All characters in this code should be uppercase.

### `pIOProc`

Pointer to the I/O procedure to install. To remove or locate an I/O procedure, set this parameter to **NULL**. For more information about the I/O procedure, see [MMIOProc](https://learn.microsoft.com/previous-versions/dd757332(v=vs.85)).

### `dwFlags`

Flag indicating whether the I/O procedure is being installed, removed, or located. The following values are defined.

| Value | Meaning |
| --- | --- |
| MMIO_FINDPROC | Searches for the specified I/O procedure. |
| MMIO_GLOBALPROC | This flag is a modifier to the MMIO_INSTALLPROC flag and indicates the I/O procedure should be installed for global use. This flag is ignored if MMIO_FINDPROC or MMIO_REMOVEPROC is specified. |
| MMIO_INSTALLPROC | Installs the specified I/O procedure. |
| MMIO_REMOVEPROC | Removes the specified I/O procedure. |

## Return value

Returns the address of the I/O procedure installed, removed, or located. Returns **NULL** if there is an error.

## Remarks

> [!NOTE]
> The mmiscapi.h header defines mmioInstallIOProc as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).