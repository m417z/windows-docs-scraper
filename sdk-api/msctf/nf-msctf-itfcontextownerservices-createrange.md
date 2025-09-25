# ITfContextOwnerServices::CreateRange

## Description

The **ITfContextOwnerServices::CreateRange** method creates a new ranged based upon a specified character position.

## Parameters

### `acpStart` [in]

Specifies the starting character position of the range.

### `acpEnd` [in]

Specifies the ending character position of the range.

### `ppRange` [out]

Receives a pointer to the range object within the specified starting and ending character positions.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The specified range is **NULL** or the specified starting character position is less than zero or the specified starting character position is greater than the specified ending character position. |