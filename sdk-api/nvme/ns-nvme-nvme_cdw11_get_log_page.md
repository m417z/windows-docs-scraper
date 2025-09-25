# NVME_CDW11_GET_LOG_PAGE structure

## Description

Contains parameters for the Get Log Page command that returns a data buffer containing the requested log page.

This structure is used in the **CDW11** field of the **GETLOGPAGE** parameter in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.NUMDU`

Specifies the number of Upper Dwords.

### `DUMMYSTRUCTNAME.LogSpecificIdentifier`

A log specific identifier.

### `AsUlong`

## Remarks

## See also

- [NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page)
- [NVME_CDW10_GET_LOG_PAGE_V13](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page_v13)
- [NVME_CDW12_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_get_log_page)
- [NVME_CDW13_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_get_log_page)