# ITfEditRecord::GetSelectionStatus

## Description

Determines if the selection has changed during the edit session.

## Parameters

### `pfChanged` [out]

Pointer to a **BOOL** value that receives a value that indicates if the selection changed due to an edit session. Receives a nonzero value if the selection changed or zero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pfChanged* is invalid. |