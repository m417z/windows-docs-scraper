# ADS_TIMESTAMP structure

## Description

The **ADS_TIMESTAMP** structure is an ADSI representation of the **Timestamp** attribute syntax.

## Members

### `WholeSeconds`

Number of seconds, with zero value being equal to 12:00 AM, January, 1970, UTC.

### `EventID`

An event identifier, in the order of occurrence, within the period specified by **WholeSeconds**.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)