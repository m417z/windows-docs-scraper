typedef struct {
  long     cb;
  char     *psz1;
  char     *psz2;
  char     *psz3;
  void     *pv;
  INT_PTR  hf;
  USHORT   date;
  USHORT   time;
  USHORT   attribs;
  USHORT   setID;
  USHORT   iCabinet;
  USHORT   iFolder;
  FDIERROR fdie;
} FDINOTIFICATION, *PFDINOTIFICATION;