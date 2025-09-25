# FltCreateSystemVolumeInformationFolder function

## Description

**FltCreateSystemVolumeInformationFolder** verifies the existence of the "System Volume Information" folder on a file system volume. If the folder is not present, then the folder is created.

## Parameters

### `Instance` [in]

Opaque instance pointer for an instance that is attached to the volume.

## Return value

**FltCreateSystemVolumeInformationFolder** returns STATUS_SUCCESS or an appropriate error status representing the final completion status of the operation. Possible error status codes include the following:

|Return code|Description|
|----|----|
|**STATUS_INSUFFICIENT_RESOURCES**|A temporary buffer required by this function could not be allocated.|

## Remarks

**FltCreateSystemVolumeInformationFolder** verifies the existence of the "System Volume Information" folder in the root directory of the volume to which the given *Instance* is attached.

If the folder is not present, then the folder is created. If the volume is an NTFS volume, the folder is created with an access control list ([ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)) containing one access control entry ([ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)) indicating full access for the local SYSTEM account, and the ACE will have the inheritance bits set. The folder will be created with the FILE_ATTRIBUTE_HIDDEN and FILE_ATTRIBUTE_SYSTEM attributes set.

If the folder is already present and the volume is an NTFS volume, the ACE that indicates full control for SYSTEM will be checked and if necessary modified to have the inheritance bits set.

For more information about security and access control, see the documentation on these topics in the Microsoft Windows SDK.

## See also

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlCreateSystemVolumeInformationFolder](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreatesystemvolumeinformationfolder)