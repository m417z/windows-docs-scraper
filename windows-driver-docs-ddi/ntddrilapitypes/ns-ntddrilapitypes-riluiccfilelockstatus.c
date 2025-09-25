struct RILUICCFILELOCKSTATUS {
  DWORD                                cbSize;
  DWORD                                dwParams;
  RILUICCFILELOCKSTATUSACCESSCONDITION dwAccessCondition;
  BYTE                                 bPinRef[MAXNUM_PINREF];
};