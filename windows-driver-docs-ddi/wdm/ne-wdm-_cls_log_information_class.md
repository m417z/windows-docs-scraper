# _CLS_LOG_INFORMATION_CLASS enumeration

## Description

The **CLFS_LOG_INFORMATION_CLASS** enumeration indicates the type of information that is requested by a call to [ClfsQueryLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsquerylogfileinformation).

## Constants

### `ClfsLogBasicInformation`

Indicates that the request is for basic information about a CLFS stream and its underlying physical log. The information is returned in a [CLFS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_information) structure. Most of the structure members contain information about the underlying physical log, but some members contain information that is specific to the stream.

### `ClfsLogBasicInformationPhysical`

Indicates that the request is for basic information about the physical log that underlies a CLFS stream. The information is returned in a **CLFS_INFORMATION** structure. All of the structure members contain information about the underlying physical log.

### `ClfsLogPhysicalNameInformation`

Indicates that the request is for information about the name of a physical CLFS log. The information is returned in a **CLFS_LOG_NAME_INFORMATION** structure.

### `ClfsLogStreamIdentifierInformation`

Indicates that the request is for a CLFS stream identifier. The information is returned in a [CLFS_STREAM_ID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_stream_id_information) structure.

### `ClfsLogSystemMarkingInformation`

Count of system marking references. This enumeration constant is supported only in Windows Vista and later versions of Windows.

### `ClfsLogPhysicalLsnInformation`

Maps virtual LSNs to physical LSNs; only valid for physical logs. This enumeration constant is supported only in Windows Vista and later versions of Windows.

## Remarks

The *eInformationClass* parameter of the [ClfsQueryLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsquerylogfileinformation) function is a value from the **CLFS_LOG_INFORMATION_CLASS** enumeration.

## See also

[ClfsQueryLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsquerylogfileinformation)