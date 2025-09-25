typedef struct RILMSGMWISUMMARY {
  RILMSGMWITYPE dwMwiType;
  DWORD         dwNumberOfNewMessages;
  DWORD         dwNumberOfOldMessages;
  DWORD         dwNumberOfNewUrgentMessages;
  DWORD         dwNumberOfOldUrgentMessages;
} RILMSGMWISUMMARY, *LPRILMSGMWISUMMARY;