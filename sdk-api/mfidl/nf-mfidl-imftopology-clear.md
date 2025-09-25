# IMFTopology::Clear

## Description

Removes all nodes from the topology.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You do not need to clear a topology before disposing of it. The **Clear** method is called automatically when the topology is destroyed.

## See also

[IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)