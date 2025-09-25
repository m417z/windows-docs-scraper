typedef union _SE_SID {
  SID   Sid;
  UCHAR Buffer[SECURITY_MAX_SID_SIZE];
} SE_SID, *PSE_SID;