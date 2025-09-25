# StorPortGetNodeAffinity function

## Description

The **StorPortGetNodeAffinity** routine constructs a mask of the active processors in a requested non-uniform memory access (NUMA) node.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `NodeNumber` [in]

The NUMA node from which to return the processor mask.

### `NodeAffinityMask` [out]

A pointer to a variable that holds the affinity mask of the given node.

## Return value

The **StorPortGetNodeAffinity**routine returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid, for example, if *NodeAffinityMask* is set to **NULL**, or if *NodeNumber* is greater than 65,535. |