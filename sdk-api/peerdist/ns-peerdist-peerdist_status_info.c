typedef struct peerdist_status_info_tag {
  DWORD           cbSize;
  PEERDIST_STATUS status;
  DWORD           dwMinVer;
  DWORD           dwMaxVer;
} PEERDIST_STATUS_INFO, *PPEERDIST_STATUS_INFO;