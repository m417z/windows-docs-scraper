# DdeCmpStringHandles function

## Description

Compares the values of two string handles. The value of a string handle is not related to the case of the associated string.

## Parameters

### `hsz1` [in]

Type: **HSZ**

A handle to the first string.

### `hsz2` [in]

Type: **HSZ**

A handle to the second string.

## Return value

Type: **int**

The return value can be one of the following values.

| Return value | Description |
| --- | --- |
| -1 | The value of *hsz1* is either 0 or less than the value of *hsz2*. |
| 0 | The values of *hsz1* and *hsz2* are equal (both can be 0). |
| 1 | The value of *hsz2* is either 0 or less than the value of *hsz1*. |

## Remarks

An application that must do a case-sensitive comparison of two string handles should compare the string handles directly. An application should use **DdeCmpStringHandles** for all other comparisons to preserve the case-insensitive nature of Dynamic Data Exchange (DDE).

**DdeCmpStringHandles** cannot be used to sort string handles alphabetically.

## See also

**Conceptual**

[DdeAccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeaccessdata)

[DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea)

[DdeFreeStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreestringhandle)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**