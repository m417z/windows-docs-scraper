APICONTRACT ULONG RegisterAppStateChangeNotification(
  [in]           PAPPSTATE_CHANGE_ROUTINE Routine,
  [in, optional] PVOID                    Context,
  [out]          PAPPSTATE_REGISTRATION   *Registration
);