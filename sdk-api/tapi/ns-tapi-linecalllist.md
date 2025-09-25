# LINECALLLIST structure

## Description

The
**LINECALLLIST** structure describes a list of call handles. A structure of this type is returned by the
[lineGetNewCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnewcalls) and
[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls) functions.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwCallsNumEntries`

Number of handles in the *hCalls* array.

### `dwCallsSize`

Size of the array of call handles, in bytes.

### `dwCallsOffset`

Offset from the beginning of the structure to the variably sized array of **HCALL** handles. The size of the array is specified by **dwCallsSize**.

## Remarks

This structure may not be extended.

## See also

[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls)

[lineGetNewCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnewcalls)