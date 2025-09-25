# DosDateTimeToVariantTime function

## Description

Converts the MS-DOS representation of time to the date and time representation stored in a variant.

## Parameters

### `wDosDate` [in]

The MS-DOS date to convert. The valid range of MS-DOS dates is January 1, 1980, to December 31, 2099, inclusive.

### `wDosTime` [in]

The MS-DOS time to convert.

### `pvtime` [out]

The converted time.

## Return value

The function returns TRUE on success and FALSE otherwise.

## Remarks

MS-DOS records file dates and times as packed 16-bit values. An MS-DOS date has the following format.

| Bits | Contents |
| --- | --- |
| 0–4 | Day of the month (1–31). |
| 5–8 | Month (1 = January, 2 = February, and so on). |
| 9–15 | Year offset from 1980 (add 1980 to get the actual year). |

An MS-DOS time has the following format.

| Bits | Contents |
| --- | --- |
| 0–4 | Second divided by 2. |
| 5–10 | Minute (0–59). |
| 11–15 | Hour (0– 23 on a 24-hour clock). |

The **DosDateTimeToVariantTime** function will accept invalid dates and try to fix them when resolving to a VARIANT time. For example, an invalid date such as 2/29/2001 will resolve to 3/1/2001. Only days are fixed, so invalid month values result in an error being returned. Days are checked to be between 1 and 31. Negative days and days greater than 31 results in an error. A day less than 31 but greater than the maximum day in that month has the day promoted to the appropriate day of the next month. A day equal to zero resolves as the last day of the previous month. For example, an invalid date such as 2/0/2001 will resolve to 1/31/2001.