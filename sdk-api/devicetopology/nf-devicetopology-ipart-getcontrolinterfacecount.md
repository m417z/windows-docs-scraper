# IPart::GetControlInterfaceCount

## Description

The **GetControlInterfaceCount** method gets the number of control interfaces that this part supports.

## Parameters

### `pCount` [out]

Pointer to a **UINT** variable into which the method writes the number of control interfaces on this part.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pCount* is **NULL**. |

## See also

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)