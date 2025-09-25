# NVME_CDW10_GET_LOG_PAGE_V13 structure

## Description

Contains parameters for the Get Log Page command that returns a data buffer containing the requested log page.

> [!NOTE] The format of the **NVME_CDW10_GET_LOG_PAGE_V13** structure conforms to NVMe Specification version 1.3 or later. For NVMe Specifications prior to version 1.3, use the [**NVME_CDW10_GET_LOG_PAGE**](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page) structure.

This structure is used in the **CDW10_V13** field of the **GETLOGPAGE** parameter in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.LID`

Specifies an [NVME_LOG_PAGES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_log_pages) value that identifies the log page to retrieve.

### `DUMMYSTRUCTNAME.LSP`

Specifies log specific information.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.RAE`

The Reset Asynchronous Event (RAE) field.

### `DUMMYSTRUCTNAME.NUMDL`

Specifies the number of Lower Dwords to return.

### `AsUlong`

## Remarks

## See also

- [NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page)
- [NVME_CDW11_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_get_log_page)
- [NVME_CDW12_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_get_log_page)
- [NVME_CDW13_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_get_log_page)