struct RILUICCLOCKSTATE {
  DWORD       cbSize;
  DWORD       dwParams;
  RILUICCLOCK rilUiccLock;
  DWORD       dwLockState;
  DWORD       dwVerifyAttemptsLeft;
  DWORD       dwUnblockAttemptsLeft;
};