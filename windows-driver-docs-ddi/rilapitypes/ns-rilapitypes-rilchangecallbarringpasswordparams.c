typedef struct RILCHANGECALLBARRINGPASSWORDPARAMS {
  DWORD                          dwExecutor;
  RILCALLBARRINGSTATUSPARAMSTYPE dwType;
  char                           szOldPassword[256];
  char                           szNewPassword[256];
  char                           szConfirmPassword[256];
} RILCHANGECALLBARRINGPASSWORDPARAMS, *LPRILCHANGECALLBARRINGPASSWORDPARAMS;