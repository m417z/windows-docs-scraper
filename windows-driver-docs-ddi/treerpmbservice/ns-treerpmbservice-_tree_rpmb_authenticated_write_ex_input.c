typedef struct _TREE_RPMB_AUTHENTICATED_WRITE_EX_INPUT {
  ULONG                          WriteFrameCount;
  ULONG                          ReliableWriteSizeOverride;
  SFFDISK_DEVICE_RPMB_DATA_FRAME Data[1];
} TREE_RPMB_AUTHENTICATED_WRITE_EX_INPUT, *PTREE_RPMB_AUTHENTICATED_WRITE_EX_INPUT;