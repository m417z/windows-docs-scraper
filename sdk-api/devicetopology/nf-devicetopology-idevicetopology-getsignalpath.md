# IDeviceTopology::GetSignalPath

## Description

The **GetSignalPath** method gets a list of parts in the signal path that links two parts, if the path exists.

## Parameters

### `pIPartFrom` [in]

Pointer to the "from" part. This parameter is a pointer to the [IPart](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart) interface of the part at the beginning of the signal path.

### `pIPartTo` [in]

Pointer to the "to" part. This parameter is a pointer to the **IPart** interface of the part at the end of the signal path.

### `bRejectMixedPaths` [in]

Specifies whether to reject paths that contain mixed data. If *bRejectMixedPaths* is **TRUE** (nonzero), the method ignores any data path that contains a mixer (that is, a processing node that sums together two or more input signals). If **FALSE**, the method will try to find a path that connects the "from" and "to" parts regardless of whether the path contains a mixer.

### `ppParts` [out]

Pointer to a pointer variable into which the method writes the address of an [IPartsList](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipartslist) interface instance. This interface encapsulates the list of parts in the signal path that connects the "from" part to the "to" part. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetSignalPath** call fails, **ppParts* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pIPartFrom*, *pIPartTo*, or *ppParts* is **NULL**. |
| **E_NOTFOUND** | No path linking the two parts was found. |
| **E_NOINTERFACE** | Parameter *pIPartFrom* or *pIPartTo* does not point to a valid **IPart** interface. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

This method creates an **IPartsList** interface instance that contains a list of the parts that lie along the specified signal path. The parts in the parts list are ordered according to their relative positions in the signal path. The "to" part is the first item in the list and the "from" part is the last item in the list.

If the list contains *n* parts, the "to" and "from" parts are identified by list indexes 0 and *n*– 1, respectively. To get the number of parts in a parts list, call the [IPartsList::GetCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipartslist-getcount) method. To retrieve a part by its index, call the [IPartsList::GetPart](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipartslist-getpart) method.

The parts in the signal path must all be part of the same device topology. The path cannot span boundaries between device topologies.

## See also

[IDeviceTopology Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)

[IPartsList Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipartslist)

[IPartsList::GetCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipartslist-getcount)

[IPartsList::GetPart](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipartslist-getpart)