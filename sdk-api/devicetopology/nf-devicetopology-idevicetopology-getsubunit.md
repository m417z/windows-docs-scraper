# IDeviceTopology::GetSubunit

## Description

The **GetSubunit** method gets the subunit that is specified by a subunit number.

## Parameters

### `nIndex` [in]

The subunit number. If a device topology contains *n* subunits, the subunits are numbered from 0 to *n*– 1. To get the number of subunits in the device topology, call the [IDeviceTopology::GetSubunitCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-idevicetopology-getsubunitcount) method.

### `ppSubunit` [out]

Pointer to a pointer variable into which the method writes the address of the [ISubunit](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-isubunit) interface of the subunit object. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetSubunit** call fails, **ppSubunit* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nIndex* is out of range. |
| **E_POINTER** | Pointer *ppSubunit* is **NULL**. |

## See also

[IDeviceTopology Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology)

[IDeviceTopology::GetSubunitCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-idevicetopology-getsubunitcount)

[ISubunit Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-isubunit)