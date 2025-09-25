# NMDAYSTATE structure

## Description

Carries information required to process the [MCN_GETDAYSTATE](https://learn.microsoft.com/windows/desktop/Controls/mcn-getdaystate) notification code. All members of this structure are for input, except
**prgDayState**, which the receiving application must set when processing MCN_GETDAYSTATE.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification code.

### `stStart`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the starting date.

### `cDayState`

Type: **int**

INT value specifying the total number of elements that must be in the array at
**prgDayState**.

### `prgDayState`

Type: **LPMONTHDAYSTATE**

Address of an array of [MONTHDAYSTATE](https://learn.microsoft.com/windows/desktop/Controls/monthdaystate) values. The buffer at this address must be large enough to contain at least
**cDayState** elements. The first element in the array corresponds to the date in
**stStart**.