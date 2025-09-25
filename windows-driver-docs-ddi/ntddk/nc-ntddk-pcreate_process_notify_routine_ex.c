PCREATE_PROCESS_NOTIFY_ROUTINE_EX PcreateProcessNotifyRoutineEx;

VOID PcreateProcessNotifyRoutineEx(
  [_Inout_]           PEPROCESS Process,
  [in]                HANDLE ProcessId,
  [in, out, optional] PPS_CREATE_NOTIFY_INFO CreateInfo
)
{...}