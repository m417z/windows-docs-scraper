# NVME_CDW10_FORMAT_NVM structure

## Description

Contains parameters for the Format NVM command that is used to low level format the NVM media.

This command is used when the host wants to change the Logical Block Address (LBA) data size and/or metadata size. A low level format may destroy all data and metadata associated with all namespaces or only the specific namespace associated with the command (refer to the Format NVM Attributes in the Optional Admin Command Support (**OACS**) field of the [Identify Controller](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure). After the Format NVM command successfully completes, the controller will not return any user data that was previously contained in an affected namespace.

The Format NVM command uses the Command Dword 10 **CDW10** field in the **FORMATNVM** parameter of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure. All other command specific fields are reserved.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.LBAF`

An [NVME_LBA_FORMAT](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_lba_format) value that specifies the LBA format to apply to the NVM media. Only supported LBA formats can be selected. This value corresponds to the **LBAF** field in the [NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) structure for the Identify command.

### `DUMMYSTRUCTNAME.MS`

Specifies the metadata settings.

When this field set to `1` if the metadata is transferred as part of an extended data LBA. This field is cleared to `0` if the metadata is transferred as part of a separate buffer. The metadata may include protection information, based on the Protection Information (**PI**) field. If the Metadata Size **MS** field of the [LBA Format](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_lba_format) selected is `0h`, then this field is not applicable.

### `DUMMYSTRUCTNAME.PI`

An [NVME_PROTECTION_INFORMATION_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_protection_information_types) enumeration value that specifies whether end-to-end data protection is enabled and the type of protection information.

### `DUMMYSTRUCTNAME.PIL`

Specifies the protection information location.

If this value is set to `1` and protection information is enabled, then protection information is transferred as the first eight bytes of metadata. If cleared to `0` and protection information is enabled, then protection information is transferred as the last eight bytes of metadata. This setting is reported in the Formatted LBA Size **LBAF** field of the [Identify Namespace data structure](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data).

### `DUMMYSTRUCTNAME.SES`

An [NVME_SECURE_ERASE_SETTINGS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_secure_erase_settings) enumeration value that specifies whether a secure erase should be performed as part of the format and the type of the secure erase operation. The erase applies to all user data, regardless of location. For example, within an exposed LBA, within a cache, or within deallocated LBAs.

### `DUMMYSTRUCTNAME.Reserved`

### `AsUlong`

## Remarks

## See also

- [NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data)
- [NVME_LBA_FORMAT](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_lba_format)