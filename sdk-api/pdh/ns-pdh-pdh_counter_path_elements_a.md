# PDH_COUNTER_PATH_ELEMENTS_A structure

## Description

The
**PDH_COUNTER_PATH_ELEMENTS** structure contains the components of a counter path.

## Members

### `szMachineName`

Pointer to a null-terminated string that specifies the computer name.

### `szObjectName`

Pointer to a null-terminated string that specifies the object name.

### `szInstanceName`

Pointer to a null-terminated string that specifies the instance name. Can contain a wildcard character.

### `szParentInstance`

Pointer to a null-terminated string that specifies the parent instance name. Can contain a wildcard character.

### `dwInstanceIndex`

Index used to uniquely identify duplicate instance names.

### `szCounterName`

Pointer to a null-terminated string that specifies the counter name.

## Remarks

This structure is used by [PdhMakeCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhmakecounterpatha) to create a counter path and by [PdhParseCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhparsecounterpatha) to parse a counter path.

When you allocate memory for this structure, allocate enough memory for the member strings, such as **szCounterName**, that are appended to the end of this structure.

## See also

[PdhMakeCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhmakecounterpatha)

[PdhParseCounterPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhparsecounterpatha)