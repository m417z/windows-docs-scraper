VIDEOPORT_DEPRECATED VIDEOPORT_API VP_STATUS VideoPortRegisterBugcheckCallback(
  [in] IN PVOID                    HwDeviceExtension,
  [in] IN ULONG                    BugcheckCode,
  [in] IN PVIDEO_BUGCHECK_CALLBACK Callback,
  [in] IN ULONG                    BugcheckDataSize
);