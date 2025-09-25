# CoDosDateTimeToFileTime function

## Description

Converts the MS-DOS representation of the time and date to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure used by Windows.

**Note** This function is provided for compatibility with 16-bit Windows.

## Parameters

### `nDosDate` [in]

The MS-DOS date.

### `nDosTime` [in]

The MS-DOS time.

### `lpFileTime` [out]

A pointer to the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Return value

If the function succeeds, the return value is **TRUE**; otherwise, it is **FALSE**, probably because of invalid arguments.

## Remarks

 An MS-DOS date has the following format.

| Bits | Description |
| --- | --- |
| 0-4 | Days of the month (1-31). |
| 5-8 | Months (1 = January, 2 = February, and so forth). |
| 9-15 | Year offset from 1980 (add 1980 to get actual year). |

An MS-DOS time has the following format.

| Bits | Description |
| --- | --- |
| 0-4 | Seconds divided by 2. |
| 5-10 | Minutes (0-59). |
| 11-15 | Hours (0-23 on a 24-hour clock). |

## See also

[CoFileTimeNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofiletimenow)

[CoFileTimeToDosDateTime](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofiletimetodosdatetime)