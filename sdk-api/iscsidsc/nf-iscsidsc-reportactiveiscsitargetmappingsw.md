# ReportActiveIScsiTargetMappingsW function

## Description

**ReportActiveIscsiTargetMappings** function retrieves the target mappings that are currently active for all initiators on the computer.

## Parameters

### `BufferSize` [in, out]

A pointer to a location that, on input, contains the size, in bytes, of the buffer that *Mappings* points to. If the operation succeeds, the location receives the size, in bytes, of the mapping data that was retrieved. If the buffer that *Mappings* points to is not sufficient to contain the output data, the location receives the buffer size, in bytes, that is required.

### `MappingCount` [out]

If the operation succeeds, the location pointed to by *MappingCount* receives the number of mappings that were retrieved.

### `Mappings` [out]

A pointer to an array of type [ISCSI_TARGET_MAPPING](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_mappinga) that, on output, is filled with the active target mappings for all initiators.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the buffer is not large enough.

Otherwise, **ReportActiveIscsiTargetMappings** returns the appropriate Win32 or iSCSI error code on failure.

## Remarks

Target mappings associate bus, target and LUN numbers with the LUNs on a target device.

> [!NOTE]
> The iscsidsc.h header defines ReportActiveIScsiTargetMappings as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ISCSI_TARGET_MAPPING](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_mappinga)