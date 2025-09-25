# GetThreadIdForInput function

## Description

Retrieves the ID of the message handling thread for the input target UI.

## Parameters

### `pointerId` [in]

The pointer ID associated with the input.

### `targetScreenPoint` [in]

The screen coordinates of the pointer, in pixels.

### `targetHWnd` [in]

The input target.

### `uiThreadId` [out]

The ID for the message handling thread of the input target UI.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also