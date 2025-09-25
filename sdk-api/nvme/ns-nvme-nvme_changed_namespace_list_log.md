# NVME_CHANGED_NAMESPACE_LIST_LOG structure

## Description

Contains data for the Changed Namespace List log page that describes namespaces in the controller that have changed [Identify Namespace](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) information since the last time the log page was read.

The Changed Namespace List log page has a size of 4096 bytes and can be retrieved by using the **NVME_ADMIN_COMMAND_GET_LOG_PAGE** [Admin Command](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands) with an **LID** value of **NVME_LOG_PAGE_CHANGED_NAMESPACE_LIST**.

## Members

### `NSID`

Specifies a list of Namespace IDs with up to 1024 entries.

If more than 1024 namespaces have changed attributes since the last time the log page was read, the first entry in the log page will be set to `FFFFFFFFh` and the remainder of the list will be zero filled.

## Remarks

## See also

- [NVME_LOG_PAGES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_log_pages)
- [NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page)
- [NVME_CDW10_GET_LOG_PAGE_V13](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page_v13)
- [NVME_CDW11_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_get_log_page)
- [NVME_CDW12_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_get_log_page)