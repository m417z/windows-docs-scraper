# MsiNotifySidChangeW function

## Description

The **MsiNotifySidChange** function notifies and updates the Windows Installer internal information with changes to user SIDs.

## Parameters

### `pOldSid` [in]

Null-terminated string that specifies the string value of the previous security identifier(SID).

### `pNewSid` [in]

Null-terminated string that specifies the string value of the new security identifier(SID).

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. This error returned if any of the parameters is **NULL**. |
| **ERROR_SUCCESS** | The function succeeded. |
| **ERROR_OUTOFMEMORY** | Insufficient memory was available. |
| **ERROR_FUNCTION_FAILED** | Internal failure during execution. |

## Remarks

**Windows Installer 2.0 and Windows Installer 3.0:** Not supported. This function is available beginning with Windows Installer 3.1.

> [!NOTE]
> The msi.h header defines MsiNotifySidChange as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Not Supported in Windows Installer 3.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-3-0)