# IAudioOutputSelector::GetSelection

## Description

The **GetSelection** method gets the local ID of the part that is connected to the selector output that is currently selected.

## Parameters

### `pnIdSelected` [out]

Pointer to a **UINT** variable into which the method writes the local ID of the part that has a direct link to the currently selected selector output.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pnIdSelected* is **NULL**. |

## Remarks

A local ID is a number that uniquely identifies a part among all parts in a device topology. To obtain a pointer to the [IPart](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart) interface of a part from its local ID, call the [IDeviceTopology::GetPartById](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-idevicetopology-getpartbyid) method.

## See also

[IAudioOutputSelector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiooutputselector)

[IDeviceTopology::GetPartById](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-idevicetopology-getpartbyid)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)