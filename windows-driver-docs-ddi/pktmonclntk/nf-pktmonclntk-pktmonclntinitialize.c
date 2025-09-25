NTSTATUS PktMonClntInitialize(
  PNPI_MODULEID                     ModuleId,
  PKTMON_CLIENT_COMP_ENUM_HANDLER   EnumComponents,
  PKTMON_CLIENT_CLEANUP_HANDLER     CleanupComponents,
  PKTMON_CLIENT_COMP_NOTIFY_HANDLER NotifyComponent
);