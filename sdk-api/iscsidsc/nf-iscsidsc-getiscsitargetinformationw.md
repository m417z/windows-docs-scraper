# GetIScsiTargetInformationW function

## Description

The **GetIscsiTargetInformation** function retrieves information about the specified target.

## Parameters

### `TargetName` [in]

The name of the target for which information is retrieved.

### `DiscoveryMechanism` [in, optional]

A text description of the mechanism that was used to discover the target (for example, "iSNS:", "SendTargets:" or "HBA:"). A value of **null** indicates that no discovery mechanism is specified.

### `InfoClass` [in]

A value of type [TARGET_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ne-iscsidsc-target_information_class) that indicates the type of information to retrieve.

### `BufferSize` [in, out]

A pointer to a location that, on input, contains the size (in bytes) of the buffer that *Buffer* points to. If the operation succeeds, the location receives the number of bytes retrieved. If the operation fails, the location receives the size of the buffer required to contain the output data.

### `Buffer` [out]

The buffer that contains the output data. The output data consists in **null**-terminated strings, with a double **null** termination after the last string.

## Return value

Returns ERROR_SUCCESS if successful and ERROR_INSUFFICIENT_BUFFER if the buffer size at Buffer was insufficient to contain the output data. Otherwise, **GetIscsiTargetInformation** returns the appropriate Win32 or iSCSI error code on failure.

## Remarks

The iSCSI initiator service can acquire information about a single target through multiple discovery mechanisms and initiators, and the information can be different in each case, so the iSCSI initiator service maintains a list of *target instances* which are organized according to the discovery method.

For instance, if a single target is discovered by multiple initiators, each of which uses a different target portal group to discover the target, the iSCSI initiator will create multiple target instances for the target, each of which refers to a different target portal group.

Since the information associated with a target is relative to the way in which it was discovered, the caller must specify the discovery mechanism in the *DiscoveryMechanism* parameter, using a correctly formatted string identifier for the discovery mechanism. The caller can retrieve a list of valid identifiers for discovery mechanisms by setting the *InfoClass* parameter to **null**.

> [!NOTE]
> The iscsidsc.h header defines GetIScsiTargetInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ISCSI_TARGET_MAPPING](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_mappinga)

[ISCSI_TARGET_PORTAL_GROUP](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portal_groupa)

[TARGETPROTOCOLTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ne-iscsidsc-targetprotocoltype)

[TARGET_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ne-iscsidsc-target_information_class)