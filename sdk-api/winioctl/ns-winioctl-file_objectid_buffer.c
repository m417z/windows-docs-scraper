typedef struct _FILE_OBJECTID_BUFFER {
  BYTE  ObjectId[16];
  union {
    struct {
      BYTE BirthVolumeId[16];
      BYTE BirthObjectId[16];
      BYTE DomainId[16];
    } DUMMYSTRUCTNAME;
    BYTE ExtendedInfo[48];
  } DUMMYUNIONNAME;
} FILE_OBJECTID_BUFFER, *PFILE_OBJECTID_BUFFER;