typedef struct _WLX_DISPATCH_VERSION_1_0 {
  PWLX_USE_CTRL_ALT_DEL           WlxUseCtrlAltDel;
  PWLX_SET_CONTEXT_POINTER        WlxSetContextPointer;
  PWLX_SAS_NOTIFY                 WlxSasNotify;
  PWLX_SET_TIMEOUT                WlxSetTimeout;
  PWLX_ASSIGN_SHELL_PROTECTION    WlxAssignShellProtection;
  PWLX_MESSAGE_BOX                WlxMessageBox;
  PWLX_DIALOG_BOX                 WlxDialogBox;
  PWLX_DIALOG_BOX_PARAM           WlxDialogBoxParam;
  PWLX_DIALOG_BOX_INDIRECT        WlxDialogBoxIndirect;
  PWLX_DIALOG_BOX_INDIRECT_PARAM  WlxDialogBoxIndirectParam;
  PWLX_SWITCH_DESKTOP_TO_USER     WlxSwitchDesktopToUser;
  PWLX_SWITCH_DESKTOP_TO_WINLOGON WlxSwitchDesktopToWinlogon;
  PWLX_CHANGE_PASSWORD_NOTIFY     WlxChangePasswordNotify;
} WLX_DISPATCH_VERSION_1_0, *PWLX_DISPATCH_VERSION_1_0;