# NVME_CDW10_GET_LOG_PAGE structure

## Description

Contains parameters for the Get Log Page command that returns a data buffer containing the requested log page.

> [!NOTE]
> The format of the **NVME_CDW10_GET_LOG_PAGE** structure conforms to NVMe Specifications prior to version 1.3. For NVMe Specification 1.3 or later, use the [**NVME_CDW10_GET_LOG_PAGE_V13**](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page_v13) structure.

This structure is used in the **CDW10** field of the **GETLOGPAGE** parameter in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.LID`

Specifies an [NVME_LOG_PAGES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_log_pages) value that identifies the log page to retrieve.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.NUMD`

Specifies the number of Dwords to return.

If the host software specifies a size larger than the requested log page, the controller returns the complete log page with undefined results for Dwords beyond the end of the log page. This is a 0’s based value.

### `DUMMYSTRUCTNAME.Reserved1`

### `AsUlong`

## Remarks

## See also

- [NVME_CDW10_GET_LOG_PAGE_V13](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page_v13)
- [NVME_CDW11_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_get_log_page)
- [NVME_CDW12_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_get_log_page)
- [NVME_CDW13_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_get_log_page)