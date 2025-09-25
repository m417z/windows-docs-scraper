# NVME_CDW11_FEATURE_LBA_RANGE_TYPE structure

## Description

Contains a parameter that specifies the number of LBA ranges for the LBA Range Type Feature in the Set Features command.

The values from this structure are used in the **LbaRangeType** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.NUM`

Specifies the number of LBA ranges in this command. This is a 0’s based value. This field is used for the Set Features command only and is ignored for the Get Features command.

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

LBA range information may be used by a driver to determine if it may utilize a particular LBA range; the information is not exposed to higher level software.

This is optional information that is not required for proper behavior of the system. However, it may be utilized to avoid unintended software issues. For example, if the LBA range indicates that it is a RAID volume then a driver that does not have RAID functionality should not utilize that LBA range (including not overwriting the LBA range). The optional information may be utilized by the driver to determine whether the LBA Range should be exposed to higher level software.

## See also

- [NVME_LBA_RANGET_TYPE_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_lba_ranget_type_entry)
- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)