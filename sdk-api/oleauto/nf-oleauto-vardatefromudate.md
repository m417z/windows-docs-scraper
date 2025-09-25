# VarDateFromUdate function

## Description

Converts a time and date converted from MS-DOS format to variant format.

## Parameters

### `pudateIn` [in]

The unpacked date.

### `dwFlags` [in]

VAR_VALIDDATE if the date is valid.

### `pdateOut` [out]

The packed date.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The UDATE structure is used with **VarDateFromUdate**, [VarDateFromUdateEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-vardatefromudateex), and [VarUdateFromDate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-varudatefromdate). It represents an unpacked date.

``` syntax
typedef struct {
    SYSTEMTIME st;
    USHORT  wDayOfYear;
} UDATE;
```

The **VarDateFromUdate** function will accept invalid dates and try to fix them when resolving to a VARIANT time. For example, an invalid date such as 2/29/2001 will resolve to 3/1/2001. Only days are fixed, so invalid month values result in an error being returned. Days are checked to be between 1 and 31. Negative days and days greater than 31 results in an error. A day less than 31 but greater than the maximum day in that month has the day promoted to the appropriate day of the next month. A day equal to zero resolves as the last day of the previous month. For example, an invalid dates such as 2/0/2001 will resolve to 1/31/2001.

Calling **VarDateFromUdate** has the same effect as calling [VarDateFromUdateEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-vardatefromudateex) with the LCID 0x0409.