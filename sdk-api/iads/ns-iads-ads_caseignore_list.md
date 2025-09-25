# ADS_CASEIGNORE_LIST structure

## Description

The **ADS_CASEIGNORE_LIST** structure is an ADSI representation of the **Case Ignore List** attribute syntax.

## Members

### `Next`

Pointer to the next **ADS_CASEIGNORE_LIST** in the list of case-insensitive strings.

### `String`

The null-terminated Unicode string value of the current entry of the list.

## Remarks

A **Case Ignore List** attribute represents an ordered sequence of case insensitive strings.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)