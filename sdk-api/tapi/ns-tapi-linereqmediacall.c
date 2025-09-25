typedef struct linereqmediacall_tag {
  HWND          hWnd;
  WPARAM        wRequestID;
  char          szDeviceClass[TAPIMAXDEVICECLASSSIZE];
  unsigned char ucDeviceID[TAPIMAXDEVICEIDSIZE];
  DWORD         dwSize;
  DWORD         dwSecure;
  char          szDestAddress[TAPIMAXDESTADDRESSSIZE];
  char          szAppName[TAPIMAXAPPNAMESIZE];
  char          szCalledParty[TAPIMAXCALLEDPARTYSIZE];
  char          szComment[TAPIMAXCOMMENTSIZE];
} LINEREQMEDIACALL, *LPLINEREQMEDIACALL;