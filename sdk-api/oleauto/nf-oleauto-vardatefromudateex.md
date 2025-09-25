# VarDateFromUdateEx function

## Description

Converts a time and date converted from MS-DOS format to variant format.

## Parameters

### `pudateIn` [in]

The unpacked date.

### `lcid` [in]

The locale identifier.

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

The UDATE structure is used with **VarDateFromUdateEx**, [VarDateFromUdate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-vardatefromudate), and [VarUdateFromDate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-varudatefromdate). It represents an unpacked date.

``` syntax
typedef struct {
    SYSTEMTIME st;
    USHORT  wDayOfYear;
} UDATE;
```

The [VarDateFromUdate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-vardatefromudate) function accepts invalid dates and tries to fix them when resolving to a VARIANT time. Only days are fixed, so invalid month values result in an error being returned. Days are checked to verify that they are in the range of 1 through 31. Negative days and days greater than 31 result in an error. A day less than 31 but greater than the maximum day in that month has the day promoted to the appropriate day of the next month. For example, an invalid date such as 2/29/2001 resolves to 3/1/2001. A day equal to zero resolves as the last day of the previous month. For example, an invalid date such as 2/0/2001 resolves to 1/31/2001.