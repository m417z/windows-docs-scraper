LRESULT VFWAPI_INLINE ICSetStatusProc(
  HIC                        hic,
  DWORD                      dwFlags,
  LRESULT                    lParam,
  LONG(* )(LPARAM,UINT,LONG) fpfnStatus
);