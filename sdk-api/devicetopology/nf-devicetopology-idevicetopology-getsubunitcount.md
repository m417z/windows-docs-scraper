# IDeviceTopology::GetSubunitCount

## Description

The **GetSubunitCount** method gets the number of subunits in the device topology.

## Parameters

### `pCount` [out]

Pointer to a **UINT** variable into which the method writes the subunit count (the number of subunits in the device topology).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pCount* is **NULL**. |

## See also

[IDeviceTopology Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology)