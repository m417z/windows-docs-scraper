LONG lineSetMediaControl(
  HLINE                             hLine,
  DWORD                             dwAddressID,
  HCALL                             hCall,
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