typedef struct _NDR_USER_MARSHAL_INFO {
  unsigned long InformationLevel;
  union {
    NDR_USER_MARSHAL_INFO_LEVEL1 Level1;
  } DUMMYUNIONNAME;
} NDR_USER_MARSHAL_INFO;