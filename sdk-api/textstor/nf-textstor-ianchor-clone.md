# IAnchor::Clone

## Description

The **IAnchor::Clone** method produces a new anchor object positioned at the same location, and with the same gravity, as the current anchor.

## Parameters

### `ppaClone` [out]

A new anchor object, identical to the current anchor.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | *ppaClone* is invalid. |

## Remarks

The change history and change history masks are both cleared in the cloned anchor.