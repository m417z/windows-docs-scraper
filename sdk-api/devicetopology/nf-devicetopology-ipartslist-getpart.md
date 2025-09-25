# IPartsList::GetPart

## Description

The **GetPart** method gets a part from the parts list.

## Parameters

### `nIndex` [in]

The part number of the part to retrieve. If the parts list contains *n* parts, the parts are numbered 0 to *n*– 1. Call the [IPartsList::GetCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipartslist-getcount) method to get the number of parts in the list.

### `ppPart` [out]

Pointer to a pointer variable into which the method writes the address of the [IPart](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart) interface of the part object. Through this method, the caller obtains a counted reference to the **IPart** interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetPart** call fails, **ppPart* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nIndex* is out of range. |
| **E_POINTER** | Pointer *ppPart* is **NULL**. |

## Remarks

For a code example that calls the **GetPart** method, see the implementation of the SelectCaptureDevice function in [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)

[IPartsList Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipartslist)

[IPartsList::GetCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipartslist-getcount)