# IEnumTfUIElements::Skip

## Description

The **IEnumTfUIElements::Skip** method obtains, from the current position, the specified number of elements in the enumeration sequence.

## Parameters

### `ulCount` [in]

[in] Specifies the number of elements to skip.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method reached the end of the enumeration before the specified number of elements could be skipped. |