# IPart::GetPartType

## Description

The **GetPartType** method gets the part type of this part.

## Parameters

### `pPartType` [out]

Pointer to a [PartType](https://learn.microsoft.com/windows/win32/api/devicetopology/ne-devicetopology-parttype) variable into which the method writes the part type. The part type is one of the following **PartType** enumeration values, which indicate whether the part is a connector or subunit:

Connector

Subunit

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pPartType* is **NULL**. |

## Remarks

For a code example that uses this method, see the implementation of the SelectCaptureDevice function in [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)