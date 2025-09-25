# ReportIScsiTargetPortalsA function

## Description

The **ReportIscsiTargetPortals** function retrieves target portal information discovered by the iSCSI initiator service.

## Parameters

### `InitiatorName` [in, optional]

A string that represents the name of the initiator node.

### `TargetName` [in]

A string that represents the name of the target for which the portal information is retrieved.

### `TargetPortalTag` [in, optional]

A **USHORT** value that represents a tag associated with the portal.

### `ElementCount` [in, out]

A **ULONG** value that specifies the number of portals currently reported for the specified target.

### `Portals` [out]

A variable-length array of an **ISCSI_TARGET_PORTALW** structure. The number of elements contained in this array is specified by the value of *ElementCount*.

## Return value

Returns **ERROR_SUCCESS** if the operation is successful. If the operation fails due to a socket connection error, this function will return a Winsock error code.

## See also

**ISCSI_TARGET_PORTALW**

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ReportIScsiTargetPortals as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).