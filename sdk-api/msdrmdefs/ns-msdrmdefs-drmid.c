typedef struct _DRMID {
  UINT  uVersion;
  PWSTR wszIDType;
  PWSTR wszID;
  void  _DRMID();
  void  _DRMID(
    PWSTR wszTypein,
    PWSTR wszIDin
  );
} DRMID;