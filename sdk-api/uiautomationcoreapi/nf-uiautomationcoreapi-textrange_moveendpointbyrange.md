# TextRange_MoveEndpointByRange function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Moves an endpoint of one range to the endpoint of another range.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

The text range object whose endpoint is to move.

### `endpoint` [in]

Type: **TextPatternRangeEndpoint**

The endpoint to move (either the start or the end).

### `targetRange` [in]

Type: **HUIATEXTRANGE**

The text range that contains the target endpoint.

### `targetEndpoint` [in]

Type: **TextPatternRangeEndpoint**

The target endpoint to move to (either the start or the end).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.