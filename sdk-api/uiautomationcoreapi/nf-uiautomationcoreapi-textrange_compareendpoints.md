# TextRange_CompareEndpoints function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Returns a value indicating whether two text ranges have identical endpoints.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `endpoint` [in]

Type: **TextPatternRangeEndpoint**

The starting or ending endpoint of *hobj*.

### `targetRange` [in]

Type: **ITextRangeInteropProvider***

The text range that is being compared against.

### `targetEndpoint` [in]

Type: **TextPatternRangeEndpoint**

The starting or ending endpoint of *targetRange*.

### `pRetVal` [out]

Type: **int***

The address of a variable that receives a pointer to a value that indicates whether two text ranges have identical endpoints.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

The returned value is <0 if the caller's endpoint occurs earlier in the text than the target endpoint;
0 if the caller's endpoint is at the same location as the target endpoint; and
>0 if the caller's endpoint occurs later in the text than the target endpoint.