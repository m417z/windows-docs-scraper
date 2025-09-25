typedef struct _TREE_RPMB_COMMAND_OUTPUT {
  ULONG                   OutputFrameCount;
  ULONG                   FramesWritten;
  STORAGE_RPMB_DATA_FRAME Data[1];
} TREE_RPMB_COMMAND_OUTPUT, *PTREE_RPMB_COMMAND_OUTPUT;