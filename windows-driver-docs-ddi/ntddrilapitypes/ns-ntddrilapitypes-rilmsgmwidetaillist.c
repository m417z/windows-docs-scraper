typedef struct RILMSGMWIDETAILLIST {
  DWORD           cbSize;
  DWORD           dwParams;
  DWORD           dwExecutor;
  DWORD           dwReferenceNumber;
  DWORD           dwNumberOfDetailItems;
  RILMSGMWIDETAIL stMwiDetail[1];
} RILMSGMWIDETAILLIST, *LPRILMSGMWIDETAILLIST;