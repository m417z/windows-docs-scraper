LONG TSPIAPI TSPI_lineSetMediaControl(
  HDRVLINE                          hdLine,
  DWORD                             dwAddressID,
  HDRVCALL                          hdCall,
  DWORD                             dwSelect,
  LPLINEMEDIACONTROLDIGIT const     lpDigitList,
  DWORD                             dwDigitNumEntries,
  LPLINEMEDIACONTROLMEDIA const     lpMediaList,
  DWORD                             dwMediaNumEntries,
  LPLINEMEDIACONTROLTONE const      lpToneList,
  DWORD                             dwToneNumEntries,
  LPLINEMEDIACONTROLCALLSTATE const lpCallStateList,
  DWORD                             dwCallStateNumEntries
);