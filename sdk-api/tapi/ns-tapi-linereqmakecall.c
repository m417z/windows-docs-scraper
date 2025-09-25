typedef struct linereqmakecall_tag {
  char szDestAddress[TAPIMAXDESTADDRESSSIZE];
  char szAppName[TAPIMAXAPPNAMESIZE];
  char szCalledParty[TAPIMAXCALLEDPARTYSIZE];
  char szComment[TAPIMAXCOMMENTSIZE];
} LINEREQMAKECALL, *LPLINEREQMAKECALL;