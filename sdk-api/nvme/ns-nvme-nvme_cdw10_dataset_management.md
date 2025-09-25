# NVME_CDW10_DATASET_MANAGEMENT structure

Contains parameters for the Dataset Management command that is used by the host to indicate attributes for ranges of logical blocks. This includes attributes like frequency that data is read or written, access size, and other information that may be used to optimize performance and reliability. This command is advisory; a compliant controller may choose to take no action based on the information provided.

The Dataset Management command uses the Command Dword 10 **CDW10** and Command Dword 11 **CDW11** fields in the **DATASETMANAGEMENT** parameter of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure. If the command uses PRPs for the data transfer, then the PRP Entry 1 **PRP1** and PRP Entry 2 **PRP2** fields are used. All other command specific fields are reserved.

The **NVME_CDW10_DATASET_MANAGEMENT** structure is used in the **CDW10** field of the **DATASETMANAGEMENT** parameter of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Description

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.NR`

The Number of Ranges (NR) field indicates the number of 16 byte range sets that are specified in the command. This is a 0’s based value.

### `DUMMYSTRUCTNAME.Reserved`

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_DATASET_MANAGEMENT](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_dataset_management)