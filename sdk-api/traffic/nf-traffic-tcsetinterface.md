# TcSetInterface function

## Description

The
**TcSetInterface** function sets individual parameters for a given interface.

## Parameters

### `IfcHandle` [in]

Handle associated with the interface to be set. This handle is obtained by a previous call to the
[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea) function.

### `pGuidParam` [in]

Pointer to the globally unique identifier (GUID) that corresponds to the parameter to be set. A list of available GUIDs can be found in
[GUID](https://learn.microsoft.com/previous-versions/windows/desktop/qos/guid).

### `BufferSize` [in]

Size of the client-provided buffer, in bytes.

### `Buffer` [in]

Pointer to a client-provided buffer. *Buffer* must contain the value to which the traffic control parameter provided in *pGuidParam* should be set.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_HANDLE** | Invalid interface handle. |
| **ERROR_INVALID_PARAMETER** | Invalid parameter. |
| **ERROR_NOT_SUPPORTED** | Setting the GUID for the provided interface is not supported. |
| **ERROR_WMI_INSTANCE_NOT_FOUND** | The GUID is not available. |
| **ERROR_WMI_GUID_NOT_FOUND** | The device did not register for this GUID. |

## Remarks

**Note** Use of the
**TcSetInterface** function requires administrative privilege. The list of GUIDs that can be set is explained in
[GUID](https://learn.microsoft.com/previous-versions/windows/desktop/qos/guid).

## See also

[GUID](https://learn.microsoft.com/previous-versions/windows/desktop/qos/guid)

[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea)