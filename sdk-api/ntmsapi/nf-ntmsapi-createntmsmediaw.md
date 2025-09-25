# CreateNtmsMediaW function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**CreateNtmsMedia** function creates a PMID and side (or sides) for a new piece of offline media. The media is placed in the media pool specified for *lpPhysicalMedia*.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMedia` [in]

Pointer to an
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure that contains information about the medium to create. For a description of the applicable members, see Remarks.

### `lpList` [in]

Pointer to an
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure that specifies array of sides associated with the medium. For a description of the applicable members, see Remarks.

### `dwOptions` [in]

Options. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Default value. Allows the creation of a duplicate medium with a duplicate OMID. |
| **NTMS_ERROR_ON_DUPLICATE** | Returns an error and does not create the medium if a medium with the specified OMID already exists on the system. |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_MODIFY_ACCESS to the computer or the media's media pool is denied. Other security errors are possible, but indicate a security subsystem error.<br><br>**Windows XP:** NTMS_CONTROL_ACCESS to the media pool or NTMS_MODIFY_ACCESS to the offline library is denied. Other security errors are possible, but indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | Database inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | Database is full. |
| **ERROR_DUPLICATE_OMID** | The option NTMS_ERROR_ON_DUPLICATE was provided and a medium already exists with this OMID. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_MEDIA** | An entry already exists for a medium with this barcode. |
| **ERROR_INVALID_MEDIA_POOL** | Media pool specified either does not exist, or is not a valid Import or Application pool. |
| **ERROR_INVALID_PARAMETER** | A parameter is missing, or the object information size or object type is not valid. |
| **ERROR_MEDIA_INCOMPATIBLE** | Number of specified sides does not match the number of sides associated with the media pool's media type. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory allocation failure during processing. |
| **ERROR_SUCCESS** | The function executed successfully. |

## Remarks

The *lpMedia* parameter must point to an
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure, whose **dwType** parameter is NTMS_PHYSICAL_MEDIA. The following is a list of members and descriptions for the
**NTMS_OBJECTINFORMATION** structure.

| Member | Description |
| --- | --- |
| **dwSize** | [in] **CreateNtmsMedia** verifies that this size equals the length of an [NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure containing an [NTMS_PMIDINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_pmidinformationa) structure. It returns ERROR_INVALID_PARAMETER if the size is incorrect. |
| **dwType** | [in] **CreateNtmsMedia** verifies that the value NTMS_PHYSICAL_MEDIA was provided. It returns ERROR_INVALID_PARAMETER if the provided type is incorrect. |
| **Created** | [out] Indicates time the physical media object was entered into the NTMS database. |
| **Modified** | [out] Indicates time the physical media object was entered into the NTMS database. |
| **ObjectGuid** | [in/out] Unique identifier for the physical media object (PMID). If a non-**NULL** value is provided, the value is used as the GUID of the Physical Medium, otherwise a GUID is generated. |
| **Enabled** | [in] Indicates whether or not the physical medium should be enabled. |
| **dwOperationalState** | [out] Must be NTMS_READY. |
| **szName** | [in/out] **CreateNtmsMedia** allows an application to specify the name of a new physical medium. This enables the application to continue to use the name of a medium after moving it from one RSM computer to another. The RSM default naming selection is: for single sided: Barcode, then Label Info value or Sequence Number;. for multi-sided media Barcode then Sequence Number. <br><br>Note that the name that appears in the RSM user interface for a partition is this name (the name assigned to the physical media object). |
| **szDescription** | [in] An optional parameter that may be set using **CreateNtmsMedia**. Provide the empty string ("\0") to avoid passing in a value for the description. |

The following is a list of members and descriptions for the
[NTMS_PMIDINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_pmidinformationa) structure.

| Member | Description |
| --- | --- |
| **CurrentLibrary** | [in] Must be either the NULL_GUID, or the GUID of the Offline library. |
| **MediaPool** | [in] Must be the GUID of a valid Import or Application pool. <br><br>**CreateNtmsMedia** verifies that this is the GUID of a valid Import or Application Pool. It also verifies that the number of partitions provided are correct for the media type associated with this media pool. |
| **Location** | [out] Must be the NULL_GUID. |
| **LocationType** | [out] Must be NTMS_STORAGESLOT. |
| **HomeSlot** | [out] Must be the NULL_GUID. |
| **MediaType** | [out] **CreateNtmsMedia** sets the media type to the media type associated with the media pool provided. |
| **szBarCode** | [in/out] The barcode is stripped of any ending spaces. **CreateNtmsMedia** does not perform any additional attempts at verifying the validity of the barcode. |
| **BarCodeState** | [out] The **BarCodeState** is set to NTMS_BARCODESTATE_UNREADABLE if the value passed in for **szBarCode** is an empty string, otherwise it is set to NTMS_BARCODESTATE_OK. |
| **szSequenceNumber** | [out] **CreateNtmsMedia** assigns the newly-created medium a sequence number, which is returned in this member. |
| **MediaState** | [out] **CreateNtmsMedia** sets the MediaState to NTMS_MEDIASTATE_IDLE. |
| **dwNumberOfPartitions** | [in] Defines the number of [NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structures representing sides for this medium. **CreateNtmsMedia** checks to ensure that the number of sides specified matches the number of sides implied by the media pool to which it is to be assigned. If they do not match, ERROR_MEDIA_INCOMPATIBLE is returned. |
| **dwMediaTypeCode** | [in] SCSI media type code. <br><br>This member is not used by RSM, but may be used by applications written to RSM for additional information about the media. For a description of what this member should be set to, see the Hardware Manufacturer's SCSI spec for possible settings.<br><br>RSM updates this member when it mounts the newly-imported medium for the first time. |
| **dwDensityCode** | [in] SCSI density code. <br><br>This member is not used by RSM, but may be used by applications written to RSM for additional information about the media. For a description of what this member should be set to, see the Hardware Manufacturer's SCSI spec for possible settings.<br><br>RSM updates this member when it mounts the newly-imported medium for the first time |

The *lpList* parameter must point to an
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure whose **dwType** is NTMS_PARTITION with the following information.

| Member | Description |
| --- | --- |
| **dwSize** | [in] **CreateNtmsMedia** verifies that the provided size matches the expected length of an [NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure containing an [NTMS_PARTITIONINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_partitioninformationa) structure. It returns ERROR_INVALID_PARAMETER if the size is incorrect. |
| **dwType** | [in] **CreateNtmsMedia** verifies that the value NTMS_PARTITION was provided. It returns ERROR_INVALID_PARAMETER if the provided type is incorrect. |
| **Created** | [out] Indicates the time that the partition object was entered into the RSM database. |
| **Modified** | [out] Indicates the time that the partition object was entered into the RSM database. |
| **ObjectGuid** | [in/out] Unique identifier for the side. If a non-**NULL** value is provided, the value is used as the GUID of the side; otherwise, a GUID is generated. |
| **Enabled** | [in] Determines whether or not the side should be enabled. |
| **dwOperationalState** | [out] Must be NTMS_READY. |
| **szName** | [in] Name of a new side. |
| **szDescription** | [in] Optional parameter that may be set using **CreateNtmsMedia**. Provide the empty string ("\0") to avoid passing in a value for the description. |
| **PhysicalMedia** | [out] GUID of the newly-created side object. |
| **LogicalMedia** | [in/out] Optional input parameter, as well as an output parameter. If the GUID is provided, **CreateNtmsMedia** attempts to create a new logical media object with the preassigned GUID. If the GUID is not unique, **CreateNtmsMedia** returns an error. |
| **State** | [in] Any valid side state. |
| **Side** | [out] **CreateNtmsMedia** sets the side number to its offset in the Partitions array. |
| **dwOmidLabelIdLength** | [in] Must be a positive value. <br><br>**CreateNtmsMedia** uses the **dwOmidLabelIdLength** to determine the number of significant bytes in the **OmidLabelId** member. If the value is not correct, the recorded **OmidLabelId** is incorrect. |
| **OmidLabelId** | [in] Must be a valid media label that can be recognized by an installed MLL. |
| **szOmidLabelType** | [in] Must not be an empty string. |
| **szOmidLabelInfo** | [in] May be the empty string. |
| **dwMountCount** | [in] Any value is accepted. |
| **dwAllocateCount** | [in] Any value is accepted. |
| **Capacity** | [in] SCSI capacity code. <br><br>This member is not used by RSM, but may be used by applications written to RSM for additional information about the media. For a description of what this member should be set to, see the Hardware Manufacturer's SCSI spec for possible settings.<br><br>RSM updates this member when it mounts the newly-imported medium for the first time. |

> [!NOTE]
> The ntmsapi.h header defines CreateNtmsMedia as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)