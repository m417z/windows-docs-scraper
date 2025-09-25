# StorPortGetLogicalProcessorRelationship function

## Description

The **StorPortGetLogicalProcessorRelationship** routine gets information about the relationships of one or more processors to the other processors in a multiprocessor system. See [**KeQueryLogicalProcessorRelationship**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerylogicalprocessorrelationship) for additional details.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `ProcessorNumber` [in, optional]

An optional pointer to a [processor number](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number) for which relationships are to be returned. To request information about all logical processors in the system, set this parameter to NULL.

### `RelationshipType` [in]

Indicates the type of relationship to be returned. See [**KeQueryLogicalProcessorRelationship**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerylogicalprocessorrelationship) for details.

### `Information` [out]

A pointer to a caller-allocated buffer that receives an array of one or more [**SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structures that contain the information requested by the caller. If the function fails, the contents of this buffer are undefined. Set **Information** to NULL to obtain the required buffer length before you allocate the buffer. See [**KeQueryLogicalProcessorRelationship**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerylogicalprocessorrelationship) for additional details.

### `Length` [in, out]

A pointer to the size of the information buffer, in bytes. On entry, **Length** contains the size of the caller-allocated buffer that **Information** points to. On return, this value receives the number of bytes that are populated with relationship information.

## Return value

The **StorPortGetLogicalProcessorRelationship**routine returns STOR_STATUS_SUCCESS if the call is successful. Possible error return values include the following.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_BUFFER_TOO_SMALL | The supplied buffer is not large enough to hold the requested information. |
| STOR_STATUS_INVALID_PARAMETER | One or more of the parameters are invalid; for example, **ProcessNumber** points to invalid information. |
| STOR_STATUS_NOT_IMPLEMENTED | This function is not implemented on the active operating system. |

## Remarks

 The information that is returned includes processor affinity masks that are composed of the logical processors in the host system. These logical processors share the specified relationship types.

See [**KeQueryLogicalProcessorRelationship**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerylogicalprocessorrelationship) for additional details.