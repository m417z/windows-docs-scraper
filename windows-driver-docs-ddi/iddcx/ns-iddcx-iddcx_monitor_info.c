struct IDDCX_MONITOR_INFO {
  UINT                                  Size;
  DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY MonitorType;
  UINT                                  ConnectorIndex;
  IDDCX_MONITOR_DESCRIPTION             MonitorDescription;
  GUID                                  MonitorContainerId;
};