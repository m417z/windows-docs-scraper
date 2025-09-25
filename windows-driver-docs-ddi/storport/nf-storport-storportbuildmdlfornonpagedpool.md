# StorPortBuildMdlForNonPagedPool function

## Description

The **StorPortBuildMdlForNonPagedPool** routine updates the MDL to describe the associated non-paged memory.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Mdl` [in, out]

A pointer to the MDL that specifies the memory buffer.

## Return value

StorPortBuildMdlForNonPagedPool returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the MDL was updated successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer to the MDL is **NULL**. |
| **STOR_STATUS_INVALID_IRQL** | The call was made at an invalid IRQL. |