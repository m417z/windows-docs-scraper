LONG TSPIAPI TSPI_lineForward(
  DRV_REQUESTID           dwRequestID,
  HDRVLINE                hdLine,
  DWORD                   bAllAddresses,
  DWORD                   dwAddressID,
  LPLINEFORWARDLIST const lpForwardList,
  DWORD                   dwNumRingsNoAnswer,
  HTAPICALL               htConsultCall,
  LPHDRVCALL              lphdConsultCall,
  LPLINECALLPARAMS const  lpCallParams
);