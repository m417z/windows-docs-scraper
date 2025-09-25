HANDLE SHChangeNotification_Lock(
  [in]            HANDLE           hChange,
                  DWORD            dwProcId,
  [out, optional] PIDLIST_ABSOLUTE **pppidl,
  [out, optional] LONG             *plEvent
);