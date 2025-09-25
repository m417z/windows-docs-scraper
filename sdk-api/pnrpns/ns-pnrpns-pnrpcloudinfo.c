typedef struct _PNRPCLOUDINFO {
  DWORD            dwSize;
  PNRP_CLOUD_ID    Cloud;
  PNRP_CLOUD_STATE enCloudState;
  PNRP_CLOUD_FLAGS enCloudFlags;
} PNRPCLOUDINFO, *PPNRPCLOUDINFO;