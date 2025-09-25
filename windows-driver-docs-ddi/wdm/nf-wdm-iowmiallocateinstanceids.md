# IoWMIAllocateInstanceIds function

## Description

The **IoWMIAllocateInstanceIds** routine allocates one or more instance IDs that are unique to the GUID.

## Parameters

### `Guid` [in]

Pointer to the GUID for which to generate instance identifiers.

### `InstanceCount` [in]

Specifies how many instance identifiers should be provided.

### `FirstInstanceId` [out]

Pointer to the first instance identifier that the driver should use.

## Return value

**IoWMIAllocateInstanceIds** returns a status code from the following list:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Indicates that WMI successfully provided unique instance identifiers for the GUID specified. |
| **STATUS_UNSUCCESSFUL** | Indicates that the WMI services are not available. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that insufficient resources were available to provide the caller with instance IDs. |

## Remarks

If greater than one instance was requested in *InstanceCount* and the routine completed successfully, *FirstInstanceId* points to the first instance that the caller should use. For each instance requested beyond one, the caller should increment the value returned in **FirstInstanceId*. For example, if the caller requested six instances and one was returned as the value of *FirstInstanceId*, the caller should use the values 1-6 as his unique instance identifiers.

## See also

[IoWmiSuggestInstanceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisuggestinstancename)