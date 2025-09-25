typedef enum COMAdminTxIsolationLevelOptions {
  COMAdminTxIsolationLevelAny = 0,
  COMAdminTxIsolationLevelReadUnCommitted,
  COMAdminTxIsolationLevelReadCommitted,
  COMAdminTxIsolationLevelRepeatableRead,
  COMAdminTxIsolationLevelSerializable
} ;