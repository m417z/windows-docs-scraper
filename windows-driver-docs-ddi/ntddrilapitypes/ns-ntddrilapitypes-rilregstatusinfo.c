typedef struct RILREGSTATUSINFO {
  DWORD               cbSize;
  DWORD               dwParams;
  DWORD               dwExecutor;
  HUICCAPP            hUiccApp;
  RILREGSTAT          dwRegStatus;
  RILACCESSTECHNOLOGY ratAccessTechnology;
  DWORD               dwSystemCaps;
  DWORD               dwRegRejectReason;
  RILOPERATORNAMES    ronCurrentOperator;
  RILVOICEDOMAIN      dwVoiceDomain;
  RILNETWORKCODE      rncNetworkCode;
} RILREGSTATUSINFO, *LPRILREGSTATUSINFO;