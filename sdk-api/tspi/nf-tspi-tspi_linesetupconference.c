LONG TSPIAPI TSPI_lineSetupConference(
  DRV_REQUESTID          dwRequestID,
  HDRVCALL               hdCall,
  HDRVLINE               hdLine,
  HTAPICALL              htConfCall,
  LPHDRVCALL             lphdConfCall,
  HTAPICALL              htConsultCall,
  LPHDRVCALL             lphdConsultCall,
  DWORD                  dwNumParties,
  LPLINECALLPARAMS const lpCallParams
);