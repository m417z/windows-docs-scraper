typedef struct _DS3DVECTOR {
  union {
    FLOAT x;
    FLOAT dvX;
  };
  union {
    FLOAT y;
    FLOAT dvY;
  };
  union {
    FLOAT z;
    FLOAT dvZ;
  };
} DS3DVECTOR, *PDS3DVECTOR;