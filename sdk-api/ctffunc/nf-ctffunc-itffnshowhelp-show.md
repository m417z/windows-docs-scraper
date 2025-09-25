# ITfFnShowHelp::Show

## Description

Called when the user selects a text service help menu item.

## Parameters

### `hwndParent` [in]

Handle of the parent window. This value can be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The text service should not wait for the help UI to be complete before returning from this method.