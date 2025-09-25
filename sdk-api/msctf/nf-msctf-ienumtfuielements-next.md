# IEnumTfUIElements::Next

## Description

The **IEnumTfUIElements::Next** method obtains, from the current position, the specified number of elements in the enumeration sequence.

## Parameters

### `ulCount` [out]

[out] Specifies the number of elements to obtain.

### `ppElement` [out]

[out] Pointer to an array of [ITfUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfuielement) interface pointer. This array must be at least *ulCount* elements in size.

### `pcFetched` [out]

[out] Pointer to a ULONG value that receives the number of elements actually obtained. This value can be less than the number of items requested. This parameter can be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method reached the end of the enumeration before the specified number of elements could be obtained. |
| **E_INVALIDARG** | One or more parameters are invalid. |