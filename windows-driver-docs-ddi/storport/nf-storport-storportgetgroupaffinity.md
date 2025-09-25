# StorPortGetGroupAffinity function

## Description

The **StorPortGetGroupAffinity** routine constructs a mask of the active processors in a requested group.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `GroupNumber` [in]

The group from which to return the processor mask.

### `GroupAffinityMask` [out]

A pointer to a variable that holds the affinity mask of the given group.

## Return value

The **StorPortGetGroupAffinity** routine returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid, for example, if *GroupAffinityMask* is set to **NULL**. |
| **STOR_STATUS_UNSUCCESSFUL** | The operation fails with this return value if one or more of the parameters are invalid, for example, if *GroupNumber* is set to a value greater than the active group count. |