typedef struct RILMSGMWIDETAIL {
  RILMSGMWITYPE     dwMwiType;
  RILMSGMWIPRIORITY dwMwiPriority;
  RILADDRESS        raToAddress;
  RILADDRESS        raFromAddress;
  RILSYSTEMTIME     stDateSent;
  WCHAR             wszSubject[256];
  WCHAR             wszMessageId[256];
} RILMSGMWIDETAIL, *LPRILMSGMWIDETAIL;