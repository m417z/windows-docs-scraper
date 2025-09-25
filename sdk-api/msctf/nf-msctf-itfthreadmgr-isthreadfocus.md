# ITfThreadMgr::IsThreadFocus

## Description

Determines if the calling thread has the TSF input focus.

## Parameters

### `pfThreadFocus` [out]

Pointer to a BOOL that receives a value that indicates if the calling thread has input focus. This parameter receives a nonzero value if the calling thread has the focus or zero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pfThreadFocus* is invalid. |