typedef struct _NET_EXTENSION {
  void  *Reserved[4];
  union {
    BOOLEAN Enabled;
    void    *Reserved1;
  } DUMMYUNIONNAME;
} NET_EXTENSION;