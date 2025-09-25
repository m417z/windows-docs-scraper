typedef struct _TREE_RPMB_COMMAND_INPUT {
  ULONG                   InputFrameCount;
  ULONG                   FramesPerTransaction;
  STORAGE_RPMB_DATA_FRAME Data[1];
} TREE_RPMB_COMMAND_INPUT, *PTREE_RPMB_COMMAND_INPUT;