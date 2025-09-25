HRESULT RIL_ManageCalls(
  HRIL                               hRil,
  LPVOID                             lpContext,
  DWORD                              dwExecutor,
  RILMANAGECALLPARAMSCOMMAND         dwCommand,
  DWORD                              dwID,
  const LPRILCALLMEDIAOFFERANSWERSET lprcmOfferAnswer,
  const LPRILADDRESS                 lpraAddress,
  const LPRILCALLRTT                 lpstRTTInfo
);