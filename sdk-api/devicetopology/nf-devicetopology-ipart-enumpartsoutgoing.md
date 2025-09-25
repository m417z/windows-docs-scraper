# IPart::EnumPartsOutgoing

## Description

The **EnumPartsOutgoing** method retrieves a list of all the outgoing parts—that is, the parts that reside on data paths that are downstream from this part.

## Parameters

### `ppParts` [out]

Pointer to a pointer variable into which the method writes the address of an [IPartsList](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipartslist) interface that encapsulates the list of parts that are immediately downstream from this part. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **EnumPartsOutgoing** call fails, **ppParts* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *ppParts* is **NULL**. |
| **E_NOTFOUND** | This part has no links to downstream parts. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

A client application can traverse a device topology in the direction of audio data flow by iteratively calling this method at each step in the traversal to get the list of parts that lie immediately downstream from the current part.

If this part has no links to downstream parts, the method returns error code E_NOTFOUND and does not create a parts list (**ppParts* is **NULL**). For example, the method returns this error code if the **IPart** interface represents a connector through which data exits a device topology.

For a code example that uses the **EnumPartsOutgoing** method, see the implementation of the SelectCaptureDevice function in [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)

[IPartsList Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipartslist)