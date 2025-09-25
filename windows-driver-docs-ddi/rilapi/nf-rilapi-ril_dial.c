HRESULT RIL_Dial(
  HRIL                               hRil,
  LPVOID                             lpContext,
  DWORD                              dwExecutor,
  const RILADDRESS                   *lpraAddress,
  DWORD                              dwOptions,
  RILCALLTYPE                        dwType,
  const LPRILCALLMEDIAOFFERANSWERSET lprcmOfferAnswer
);