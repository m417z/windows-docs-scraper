typedef struct RILMSGMWISUMMARYLIST {
  DWORD            cbSize;
  DWORD            dwParams;
  DWORD            dwExecutor;
  DWORD            dwReferenceNumber;
  RILADDRESS       stAccountAddress;
  DWORD            dwTotalNumberOfDetailItems;
  DWORD            dwNumberOfSummaryItems;
  RILMSGMWISUMMARY stMwiSummary[1];
} RILMSGMWISUMMARYLIST, *LPRILMSGMWISUMMARYLIST;