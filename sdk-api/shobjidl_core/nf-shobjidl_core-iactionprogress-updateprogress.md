# IActionProgress::UpdateProgress

## Description

Updates the progress of an action to the UI.

## Parameters

### `ulCompleted` [in]

Type: **ULONGLONG**

The amount of the action completed.

### `ulTotal` [in]

Type: **ULONGLONG**

The total amount of the action.

## Return value

Type: **HRESULT**

Return S_OK if successful, or an error value otherwise.

## Remarks

This method should be called periodically to update the progress of the action. The implementing class may interpret these values in any way desired, although the values of *ulCompleted* and *ulTotal* should be interpreted relative to one another to determine a meaningful progress amount. Often, a percentage is desired, in which case the value of *ulCompleted* should be divided by *ulTotal*, and the result multiplied by a value of 100.